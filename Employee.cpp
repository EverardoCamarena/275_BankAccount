#include "Employee.h"
#include<iomanip>
#include<iostream>

using namespace std;

Employee::Employee(std::string id, std::string n, double s, BankAccount *a){
    this->id = id;
    this->name = n;
    this->salary = s;
    this->account = a;
}

void Employee::deposit_monthly_salary(){
    this->account->deposit(salary / 12);
}

void Employee::print() const{
    // extract the first and last name from the name
    int space = name.find(' ');
    string firstName = name.substr(0, space);
    string lastName = name.substr(space + 1);
    // print the data to console
    cout << left << setw(16) << id
         << "\t"
         << left << setw(14) << lastName
         << "\t"
         << left << setw(15) << firstName
         << "\t"
         << left << setw(18) << setprecision(2) << fixed << salary
         << "\t"
         << left << setw(19) << setprecision(2) << fixed << (salary / 12)
         << "\t"
         << left << setw(12) << setprecision(2) << fixed << account->get_balance()
         << "\n";
}

void Employee::print(std::ostream &out) const{
    //take first and last name
    int space = name.find(' ');
    string firstName = name.substr(0, space);
    string lastName = name.substr(space + 1);
    
    out << left << setw(16) << id
        << "\t"
        << left << setw(14) << lastName
        << "\t"
        << left << setw(15) << firstName
        << "\t"
        << left << setw(18) << setprecision(2) << fixed << salary
        << "\t"
        << left << setw(19) << setprecision(2) << fixed << (salary / 12)
        << "\t"
        << left << setw(12) << setprecision(2) << fixed << account->get_balance()
        << "\n";
}
