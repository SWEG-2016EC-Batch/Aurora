/*Design an algorithm and write a to read an employee name, weekly working hours, bonus rate per hour and base salary and find the employees gross-salary,
  net salary and bonus payment. (Hint: pension rate – 5%, tax: 15%).*/
#include<iostream>
using namespace std;

int main() {
    string name;
    float base_salary, weekly_working_hours;
    float tax, pension, bonus_rate, gross_salary, net_salary, bonus;

    cout << "Please enter your name: " << endl;
    cin >> name;

    cout << "Please enter base salary: " << endl;
    cin >> base_salary;

    cout << "Please enter bonus rate per hour: " << endl;
    cin >> bonus_rate;

    cout << "Please enter weekly working hours: " << endl;
    cin >> weekly_working_hours;

    bonus = bonus_rate * weekly_working_hours;
    gross_salary = base_salary + bonus;
    tax = 0.15 * gross_salary;
    pension = 0.05 * base_salary;
    net_salary = gross_salary - tax - pension;

    cout << "The net salary of " << name << " is " << net_salary << endl;
    cout << "The bonus of " << name << " is " << bonus << endl;
    cout << "The gross salary of " << name << " is " << gross_salary << endl;

    return 0;
}

