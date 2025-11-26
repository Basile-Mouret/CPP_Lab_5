#include "client.hpp"
#include "account.hpp"


Client::Client(string name, unsigned int id, int max_nb_account){
    this->name = name;
    this->id = id;
    this->accounts = new Account *[max_nb_account];
    this->max_nb_account = max_nb_account;
    this->current_nb_account = 0;
}


Client::Client(const Client &client){
    this->name = client.name;
    this->id = client.id;
    this->max_nb_account = client.max_nb_account;
    this->accounts = new Account *[client.max_nb_account];
    for (int i=0; i<client.current_nb_account; i++) {
      this->accounts[i] = client.accounts[i]->clone();
    }
    this->current_nb_account = client.current_nb_account;

}

Client::~Client(){
  for (int i=0; i<current_nb_account; i++) {
    delete this->accounts[i];
  }
  delete[] this->accounts;
}

Client &Client::operator=(const Client &client){
    if (&client==this){
        return *this;
    }
    this->name = client.name;
    this->id = client.id;
    this->max_nb_account = client.max_nb_account;

    for (int i=0; i<this->current_nb_account; i++) {
      delete this->accounts[i];
    }
    delete[] this->accounts;

    this->max_nb_account = client.max_nb_account;
    this->accounts = new Account *[client.max_nb_account];

    for (int i=0; i<client.current_nb_account; i++){
      this->accounts[i] = client.accounts[i]->clone();
    }
    this->current_nb_account = client.current_nb_account;
    return (*this);
}

unsigned int Client::get_id() const{
    return this->id;
}

void Client::createAccount(){
  string choice;
  if (this->current_nb_account<max_nb_account){
    cout << "Creation of accounts for " << this->name << endl;
    cout << "Creation of a current accout (1), unblocked savings account(2), or blocked savings account(3)?" << endl;
    cin >> choice;
    if (choice=="1"){
      this->accounts[this->current_nb_account] = new CurrentAccount(current_nb_account);
      this->current_nb_account+=1;
    }
    else if (choice=="2"){
      this->accounts[this->current_nb_account] = new UnblockedSavingsAccount(current_nb_account);
      this->current_nb_account+=1;
    }
    else if (choice=="3"){
      this->accounts[this->current_nb_account] = new BlockedSavingsAccount(current_nb_account);
      this->current_nb_account+=1;
    }
    else{
      cout << "Invalid input, account creation abborted";
    }
  }
}

void Client::creditAccount(double amount){
  string choice;
  cout << "These are your accounts : \n";
  for (int i=0; i<this->current_nb_account; i++){
    
    cout << *(this->accounts[i]) << endl;
  }
  cout << "Which one do you want to credit?\naccount : ";
  cin >> choice;

  if (stoi(choice)>0 && stoi(choice)<=this->current_nb_account){
    this->accounts[stoi(choice)-1]->credit(amount);
  }
  else{
    cout << "Invalid input, operation cancelled." << endl;
  }
}

double Client::debitAccount(double amount){
  string choice;
  cout << "These are your accounts : \n";
  for (int i=0; i<this->current_nb_account; i++){
    cout << *(this->accounts[i]) << endl;
  }
  cout << "Which one do you want to debit?\naccount : ";
  cin >> choice;

  if (stoi(choice)>0 && stoi(choice)<=this->current_nb_account ){
    return this->accounts[stoi(choice)-1]->debit(amount);
  }
  else{
    cout << "Invalid input, operation cancelled." << endl;
  }

  return 0;
}

ostream& operator<<(ostream &o, const Client &client){
    o<< "\nclient name : " << client.name << "\nclient id : " << client.id << "\nAccounts : \n";
    for (int i=0; i<client.current_nb_account; i++){
      if (client.accounts[i]!=NULL){
        o << *(client.accounts[i]) << "\n";
      }
    }
    return o;
}
