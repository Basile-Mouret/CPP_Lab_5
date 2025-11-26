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
        Account **accounts;
        int max_nb_account;
        int current_nb_account;
    public:
        Client(string name, unsigned int id, int max_nb_account);
        Client(const Client &client); //copy constructor
        ~Client(); //destructor
        Client &operator=(const Client &client);

        unsigned int get_id() const;
        void createAccount();
        void creditAccount(double amount);
        double debitAccount(double amount);
        friend ostream& operator<<(ostream &o, const Client &client);
};
#endif
