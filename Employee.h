#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "BankAccount.h"

class Employee{
	public:
	/**
       Constructs an employee with a id, given name, salary, and
       bank account.
       @param id the id
       @param n the name
       @param s the annual salary
       @param a a pointer to the bank account
    */
    Employee(std::string id, std::string n, double s, BankAccount *a);
    /**
       Deposits one month's salary into the bank account.
    */
    void deposit_monthly_salary();
    /**
       Prints this employee's information to cout.
    */
    void print() const;
    /**
       Prints this employee's information to output file.
    */
    void print(std::ostream &out) const;
	private:
		std::string id;
    	std::string name;
    	double salary;
    	BankAccount *account;

};

#endif