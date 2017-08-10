#pragma once

#include <windows.h>

template <typename C>
class UniqueHandle
{
private:
    HANDLE m_val;

	void Close()
	{
		if (*this)
		{
			C::Exit(m_val);
		}
	}

public:
    // Copy assignment operator 
	UniqueHandle(UniqueHandle const &) = delete;
	auto operator=(UniqueHandle const &)->UniqueHandle & = delete;

    // UniqueHandle constructor
	explicit UniqueHandle(HANDLE value = C::Invalid()) :
		m_val{ value }
	{
	}

    // Move assignment operator
	UniqueHandle(UniqueHandle && other) :
		m_val{ other.Release() }
	{
	}

    // Move assignment operator
	auto operator=(UniqueHandle && other) -> UniqueHandle &
	{
		if (this != &other)
		{
			Reset(other.Release());
		}

		return *this;
	}

    // Destructor of UniqueHandle class
	~UniqueHandle()
	{
		Close();
	}

    // bool operator for equality
	explicit operator bool() const 
	{
		return m_val != C::Invalid();
	}

    // Method for retrieving the HANDLE value
	HANDLE Get() const
	{
		return m_val;
	}

    // Method for releasing the HANDLE value
	HANDLE Release()
	{
		auto value = m_val;
		m_val = C::Invalid();
		return value;
	}

    // Method for reseting the HANDLE
	bool Reset(HANDLE value = C::Invalid())
	{
		if (m_val != value)
		{
			Close();
			m_val = value;
		}

		return static_cast<bool>(*this);
	}
};

template <typename C>
auto swap(UniqueHandle<C> & left,
	UniqueHandle<C> & right) throw() -> void
{
	left.swap(right);
}

template <typename C>
auto operator==(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() == right.Get();
}

template <typename C>
auto operator!=(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() != right.Get();
}

template <typename C>
auto operator<(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() < right.Get();
}

template <typename C>
auto operator>=(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() >= right.Get();
}

template <typename C>
auto operator>(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() > right.Get();
}

template <typename C>
auto operator<=(UniqueHandle<C> const & left,
	UniqueHandle<C> const & right) throw() -> bool
{
	return left.Get() <= right.Get();
}

struct NullHandleCharacteristics
{
    // Returning nullptr when the HANDLE is invalid
    static HANDLE Invalid()
    {
        return nullptr;
    }
    
    // Exit the HANDLE by closing it
    static void Exit(HANDLE val)
    {
        CloseHandle(val);
    }
};

//struct invalid_handle_traits
//{
//	using pointer = HANDLE;
//
//	static auto invalid() throw() -> pointer
//	{
//		return INVALID_HANDLE_VALUE;
//	}
//
//	static auto close(pointer value) throw() -> void
//	{
//		CloseHandle(value);
//	}
//};

using NullHandle = UniqueHandle<NullHandleCharacteristics>;
//using invalid_handle = unique_handle<invalid_handle_traits>;

