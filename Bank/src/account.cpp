#include "account.hpp"
#include <ostream>

Account::Account(unsigned int id){
    this->id = id;
    this->balance=0;
}

void Account::credit(double amount){
    this->balance += amount;
}

void Account::print(ostream &o) const{
    o << "ID : " << id << "\nBalance : " << balance;
}

float Account::operator()(){
    return balance;
}

ostream &operator<<(ostream &os, const Account &account){
  account.print(os);
  return os;
}

CurrentAccount::CurrentAccount(unsigned int id) : Account(id){}

double CurrentAccount::debit(double amount){
    if (balance>=amount){
        balance-=amount;
        return amount;
    }
    else if (balance==0) {
        return 0;
    }
    else{
        amount=balance;
        balance = 0;
        return amount;
    }
}

void CurrentAccount::print(ostream &o)const{
    o << "** Current Account **\n";
    Account::print(o);
}

SavingsAccount::SavingsAccount(unsigned int id, unsigned int rate) : Account(id) {
    this->rate=rate;
}

double SavingsAccount::add_interrest(){
    credit(balance*rate);
    return balance;
}

void SavingsAccount::print(ostream &o) const{
    o << "** Savings Account **\n";
    Account::print(o);
}



BlockedSavingsAccount::BlockedSavingsAccount(unsigned int id):SavingsAccount(id, IRATEBLOCKED){}

void BlockedSavingsAccount::print(ostream &o) const{
    o << "** Blocked Savings Account **\n";
    Account::print(o);
}

double BlockedSavingsAccount::debit(double amount){return -1;}

UnblockedSavingsAccount::UnblockedSavingsAccount(unsigned int id):SavingsAccount(id, IRATEUNBLOCKED){}

double UnblockedSavingsAccount::debit(double amount){
    if (balance>=amount){
        balance-=amount;
        return amount;
    }
    else{
        return 0;
    }
}

void UnblockedSavingsAccount::print(ostream &o) const{
    o << "** Unblocked Savings Account **\n";
    Account::print(o);
}
