#include "BankAccount.h"

BankAccount::BankAccount(){
    this->balance = 2000;
}

void BankAccount::deposit(double amount){
    this->balance += amount;
}

void BankAccount::withdraw(double amount){
    this->balance -= amount;
}

double BankAccount::get_balance() const{
    return this->balance;
}

std::string BankAccount::get_id() const{
    return this->id;
}

void BankAccount::set_id(std::string id){
    this->id = id;
}