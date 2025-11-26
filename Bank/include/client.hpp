#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>
#include "account.hpp"

using namespace std;


class Client{
    private:
        string name;
        unsigned int id;
        CurrentAccount *current;
        UnblockedSavingsAccount *savings;
    public:
        Client(string name, unsigned int id, bool hascurrent, bool hasunblocked);
        Client(const Client &client); //copy constructor
        ~Client(); //destructor
        Client &operator=(const Client &client);

        unsigned int get_id() const;
        void credit_current(double amount);
        void credit_savings(double amount);
        double debit_current(double amount);
        double debit_savings(double amount);
        friend ostream& operator<<(ostream &o, const Client &client);
};
#endif