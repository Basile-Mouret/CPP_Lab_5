#ifndef BANK_HPP
#define BANK_HPP

#include <map>
#include <iostream>
#include "client.hpp"

class Bank{
    private:
        map<unsigned int, Client *> clients;
    public:
        Bank();
        void insertClient(Client &client);
        friend ostream &operator<<(ostream &os, const Bank &bank);

};

#endif
