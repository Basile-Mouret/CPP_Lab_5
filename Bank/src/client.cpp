#include "client.hpp"


Client::Client(string name, unsigned int id, bool hascurrent, bool hasunblocked){
    this->name = name;
    this->id = id;
    if (hascurrent){
        current = new CurrentAccount(1);
    } else {
        current = NULL;
    }
    if (hasunblocked){
        savings = new UnblockedSavingsAccount(2);
    } else {
        savings = NULL;
    }
}


Client::Client(const Client &client){
    this->name = client.name;
    this->id = client.id;
    if (current != NULL) {current = new CurrentAccount(*client.current);}
    else{current = NULL;}

    if (savings != NULL) {savings = new UnblockedSavingsAccount(*client.savings);}
    else{savings = NULL;}
}

Client::~Client(){
    delete current;
    delete savings;
}

Client &Client::operator=(const Client &client){
    if (&client==this){
        return *this;
    }
    this->name = client.name;
    this->id = client.id;

    delete this->current;
    if (client.current != NULL) {this->current = new CurrentAccount(*client.current);}
    else{current = NULL;}

    delete this->savings;
    if (client.savings != NULL) {this->savings = new UnblockedSavingsAccount(*client.savings);}
    else{savings = NULL;}
    return (*this);
}

unsigned int Client::get_id() const{
    return this->id;
}

void Client::credit_current(double amount){
    if (current!=NULL){
        current->credit(amount);
    }
}
void Client::credit_savings(double amount){
    if (savings!=NULL){
        savings->credit(amount);
    }
}
double Client::debit_current(double amount){
    if (current!=NULL){
        return current->debit(amount);
    }
    return 0;
}
double Client::debit_savings(double amount){
    if (savings!=NULL){
        return savings->debit(amount);
    }
    return 0;
}

ostream& operator<<(ostream &o, const Client &client){
    o<< "\nclient name : " << client.name << "\nclient id : " << client.id << "\nAccounts : \n";
    if (client.current!=NULL){
        client.current->print(o);
        o << "\n";
    }
    
    if (client.savings!=NULL){
        client.savings->print(o);
        o << "\n";
    }
    return o;
}
