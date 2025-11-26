#include "account.hpp"
#include "client.hpp"
#include <iostream>


using namespace std;

int main(){
    CurrentAccount current = CurrentAccount(1);
    BlockedSavingsAccount blocked = BlockedSavingsAccount(2);
    UnblockedSavingsAccount unblocked = UnblockedSavingsAccount(3);
    current.credit(1000);
    blocked.credit(100000);
    unblocked.credit(20000);

    current.print(cout);
    blocked.print(cout);
    unblocked.print(cout);
    

    unblocked.credit(current.debit(500));
    blocked.credit(current.debit(1000));

    current.print(cout);
    blocked.print(cout);
    unblocked.print(cout);

    blocked.add_interrest();
    unblocked.add_interrest();
    current.credit(1);

    current.print(cout);
    blocked.print(cout);
    unblocked.print(cout);

    cout << endl;

    Client client1("Patrick",1,true,false);
    Client client2("Martha",2,true,true);
    Client client3("Fred",3,true,true);
    client1.credit_current(100);
    client2.credit_current(1000);
    client2.credit_savings(client2.debit_current(990));

    client2.credit_current(client1.debit_current(20));
    client3.credit_current(client2.debit_current(50));

    cout << client1 << client2 << client3 << endl;
    return 0;
}