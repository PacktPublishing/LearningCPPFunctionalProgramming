/* Customer.h - Step03 */
#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <string>
#include <vector>
#include <memory>

class Customer
{
private:
    template<typename T, typename U>
    class BaseClass
    {
    public:
        virtual U InvokeFunction(
            const std::shared_ptr<T>&) = 0;
    };

    class CustomerName :
        public BaseClass<Customer, std::string>
    {
    public:
        virtual std::string InvokeFunction(
            const std::shared_ptr<Customer> &customer)
        {
            return customer->name;
        }
    };

    class CustomerAddress :
        public BaseClass<Customer, std::string>
    {
    public:
        virtual std::string InvokeFunction(
            const std::shared_ptr<Customer> &customer)
        {
            return customer->address;
        }
    };

    class CustomerPhoneNumber :
        public BaseClass<Customer, std::string>
    {
    public:
        virtual std::string InvokeFunction(
            const std::shared_ptr<Customer> &customer)
        {
            return customer->phoneNumber;
        }
    };

    class CustomerEmail :
        public BaseClass<Customer, std::string>
    {
    public:
        virtual std::string InvokeFunction(
            const std::shared_ptr<Customer> &customer)
        {
            return customer->email;
        }
    };

public:
    static std::vector<Customer> registeredCustomers;
    int id = 0;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    bool isActive = true;

    static std::vector<std::string> GetActiveCustomerNames();
    static std::vector<std::string> GetActiveCustomerAddresses();
    static std::vector<std::string> GetActiveCustomerPhoneNumbers();
    static std::vector<std::string> GetActiveCustomerEmails();

    template<typename T>
    static std::vector<T> GetActiveCustomerByFunctionField(
        const std::shared_ptr<BaseClass<Customer, T>>
            &classField);
};
#endif // __CUSTOMER_H__
