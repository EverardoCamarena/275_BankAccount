#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include"BankAccount.h"
#include"Employee.h"

using namespace std;

double removeComma(string salary_str){
    string s; 
    
    for (auto co : salary_str){
        //remove potential commas from output
        if (co != ',')
            s += co;
    }
    //salary in double
    return stod(s);
}

//read employee data and return a vector
vector<Employee> readEmployees(){
    ifstream in_file("salary.txt");

    vector<Employee> employees;

    string id, firstName, lastName, salary_str;

    //pointer to bank account
    BankAccount *account;

    //read content of file
    while (!in_file.eof()){
        in_file >> id >> lastName >> firstName >> salary_str;

        double salary_double = removeComma(salary_str); // get the salary in double

        //create a bank account
        account = new BankAccount();
       
        account->set_id(id);

        string fullName = firstName + " " + lastName;

        //create an employee object and push it to the vector
        Employee employee(id, fullName, salary_double, account);
        employees.push_back(employee);
    }

    //close file
    in_file.close();

    return employees;
}

//write to the output file
void writeData(vector<Employee> employees){
    ofstream out_file("monthly_salary.txt");

    //headers
    out_file << left << setw(16) << "Employee ID"
             << "\t"
             << left << setw(14) << "Last Name"
             << "\t"
             << left << setw(15) << "First Name"
             << "\t"
             << left << setw(18) << "Annual Salary"
             << "\t"
             << left << setw(19) << "Monthly Salary"
             << "\t"
             << left << setw(12) << "Balance"
             << "\n";

    //display data to output file
    for (auto &e : employees)
    {
        e.print(out_file);
    }

    //close file
    out_file.close();
}

int main(){
    //read the employees
    vector<Employee> employees = readEmployees();
    //deposit salary
    for (auto &emp : employees)
    {
        emp.deposit_monthly_salary();
    }

    //write to output file
    writeData(employees);
    return 0;
}