#include "account.hpp"
#include "client.hpp"
#include "bank.hpp"
#include <iostream>


using namespace std;

int main(){
    Bank bank;
    Client client1("Patrick",1,true,false);
    bank.insertClient(client1);

    Client client2("Martha",2,true,true);
    bank.insertClient(client2);

    Client client3("Fred",3,true,true);
    bank.insertClient(client3);

    client1.credit_current(100);
    client2.credit_current(1000);
    client2.credit_savings(client2.debit_current(990));

    client2.credit_current(client1.debit_current(20));
    client3.credit_current(client2.debit_current(50));

    cout << bank << endl;
    return 0;
}
