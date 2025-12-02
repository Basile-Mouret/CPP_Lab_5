#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

#define IRATEBLOCKED 4
#define IRATEUNBLOCKED 2

using namespace std;

class Account{
    private:
        unsigned int id;
    protected:
        double balance;
    public:
        Account(unsigned int id);

        void credit(double amount);
        virtual double debit(double amount)=0; // pure virtual method
        virtual void print(ostream &o) const;
        virtual Account *clone() const=0;
        float operator()();
        friend ostream &operator<<(ostream &os, const Account &account);
};

class CurrentAccount : public Account {
    public:
        CurrentAccount(unsigned int id);
        double debit(double amount);
        void print(ostream &o) const;
        Account *clone() const;
};

class SavingsAccount : public Account {
    private:
        unsigned int rate;
    public:
        SavingsAccount(unsigned int id,unsigned int rate);
        double add_interrest();
        void print(ostream &o) const;
};

class BlockedSavingsAccount : public SavingsAccount {
    public:
        BlockedSavingsAccount(unsigned int id);
        double debit(double amount);
        void print(ostream &o) const;
        Account *clone() const;
};

class UnblockedSavingsAccount : public SavingsAccount {
    public:
        UnblockedSavingsAccount(unsigned int id);
        double debit(double amount);
        void print(ostream &o) const;
        Account *clone() const;
};

#endif
