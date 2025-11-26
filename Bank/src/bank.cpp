#include <map>
#include <iostream>
#include "client.hpp"
#include "bank.hpp"

using namespace std;

Bank::Bank(){}
void Bank::insertClient(const Client &client){
    clients[client.get_id()] = &client;
}

ostream &operator<<(ostream &os, const Bank &bank){
    for (map<unsigned int, Client *>::iterator i=bank.clients.begin(); i!=bank.clients.end(); i++){
        os << *(i->second) << endl;
    }
    return os;
}