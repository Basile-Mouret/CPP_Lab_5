#include "account.hpp"
#include "client.hpp"
#include "bank.hpp"
#include <iostream>


using namespace std;

int main(){
    Bank bank;
    Client client1("Patrick",2);
    bank.insertClient(client1);

    Client client2("Martha",3);
    bank.insertClient(client2);


    client1.createAccount();
    client1.createAccount();
    client1.creditAccount(1000);
    client1.creditAccount(client1.debitAccount(900));

    client2.createAccount();
    client2.creditAccount(100);
    client1.creditAccount(client2.debitAccount(20));

    Client client4(client2);
    cout << "client 4 is a copy of client 2" << endl;
    bank.insertClient(client4);

    client4.creditAccount(client1.debitAccount(100));

    cout << bank << endl;
    return 0;
}
