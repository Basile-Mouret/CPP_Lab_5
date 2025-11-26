#include <map>
#include <iostream>
#include "bank.hpp"
#include "client.hpp"

using namespace std;

Bank::Bank(){}
void Bank::insertClient(Client &client){
    clients[client.get_id()] = &client;
}

ostream &operator<<(ostream &os, const Bank &bank){
    for (map<unsigned int, Client *>::const_iterator i=bank.clients.begin(); i!=bank.clients.end(); i++){
        os << *(i->second) << endl;
    }
    return os;
}
