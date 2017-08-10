/* Customer.h - Step06 */
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
    int id = 0;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    bool isActive = true;

    static std::vector<std::string> GetActiveCustomerNames(
        std::vector<Customer> customer);
    static std::vector<std::string> GetActiveCustomerAddresses(
        std::vector<Customer> customer);
    static std::vector<std::string> GetActiveCustomerPhoneNumbers(
        std::vector<Customer> customer);
    static std::vector<std::string> GetActiveCustomerEmails(
        std::vector<Customer> customer);

    static int CountActiveCustomers(
        std::vector<Customer> customer);

    template<typename T>
    static std::vector<T> GetActiveCustomerByFunctionField(
        std::vector<Customer> customers,
        const std::shared_ptr<BaseClass<Customer, T>>
            &classField);
};
#endif // __CUSTOMER_H__
