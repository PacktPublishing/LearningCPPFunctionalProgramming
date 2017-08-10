/* lazyevaluation.h */
#include <functional>
#include <memory>

template<class T> class Row;

template<class T> class Memoization
{
private:
    typedef T const & (*subRoutine)(
        Memoization const *);
    mutable subRoutine m_subRoutine;
    mutable T   m_recordedFunc;
    std::function<T()> m_func;

    static T const & ForceSubroutine(
        Memoization const * d)
    {
        return d->DoRecording();
    }

    static T const & FetchSubroutine(
        Memoization const * d)
    {
        return d->FetchRecording();
    }

    T const & FetchRecording() const
    {
        return m_recordedFunc;
    }

    T const & DoRecording() const
    {
        m_recordedFunc = m_func();
        m_subRoutine = FetchSubroutine;
        return FetchRecording();
    }

public:
    Memoization()
    {
    }

    explicit Memoization(
        std::function<T()> func)
        : m_func(func),
        m_subRoutine(&ForceSubroutine),
        m_recordedFunc(T())
    {
    }

    T const & Fetch() const
    {
        return m_subRoutine(this);
    }
};

template<class T> class Chunk
{
private:
    T m_value;
    Row<T> m_lastRow;

public:
    Chunk()
    {
    }

    Chunk(T value, Row<T> lastRow)
        : m_value(value),
        m_lastRow(
            std::move(lastRow))
    {
    }

    explicit Chunk(T value) :
        m_value(value)
    {
    }

    T Value() const
    {
        return m_value;
    }

    Row<T> ShiftLastToFirst() const
    {
        return m_lastRow;
    }
};

template<class T> class ChunkPreparation
{
public:
    T m_value;
    Row<T> m_row;

    ChunkPreparation(T value, Row<T> row) :
        m_value(value),
        m_row(std::move(row))
    {
    }

    explicit ChunkPreparation(T value) :
        m_value(value)
    {
    }

    Chunk<T> operator()()
    {
        return Chunk<T>(
            m_value,
            m_row);
    }
};

template<class T> class Row
{
private:
    std::shared_ptr <Memoization<Chunk<T>>>
        m_lazyChunk;

public:
    Row()
    {
    }

    explicit Row(T value)
    {
        auto chunk = ChunkPreparation<T>(value);
        m_lazyChunk = std::make_shared<Memoization<Chunk<T>>>(
            chunk);
    }

    Row(T value, Row row)
    {
        auto chunk = ChunkPreparation<T>(
            value,
            std::move(row));

        m_lazyChunk = std::make_shared<Memoization<Chunk<T>>>(
            chunk);
    }

    Row(std::function<Chunk<T>()> func)
        : m_lazyChunk(
            std::make_shared<Memoization<Chunk<T>>>(func))
    {
    }

    bool IsEmpty() const
    {
        return !m_lazyChunk;
    }

    T Fetch() const
    {
        return m_lazyChunk->Fetch().Value();
    }

    Row<T> ShiftLastToFirst() const
    {
        return m_lazyChunk->Fetch().ShiftLastToFirst();
    }

    Row Pick(int n) const
    {
        if (n == 0 || IsEmpty())
            return Row();

        auto chunk = m_lazyChunk;
        return Row([chunk, n]()
        {
            auto val = chunk->Fetch().Value();
            auto row = chunk->Fetch().ShiftLastToFirst();
            return Chunk<T>(val, row.Pick(n - 1));
        });
    }
};

template<class T> Row<T> ConcatenateRows(
    Row<T> leftRow,
    Row<T> rightRow)
{
    if (leftRow.IsEmpty())
        return rightRow;

    return Row<T>([=]()
    {
        return Chunk<T>(
            leftRow.Fetch(),
            ConcatenateRows<T>(
                leftRow.ShiftLastToFirst(),
                rightRow));
    });
}

template<class T, class U> void ForEach(
    Row<T> row, U func)
{
    while (!row.IsEmpty())
    {
        func(row.Fetch());
        row = row.ShiftLastToFirst();
    }
}
