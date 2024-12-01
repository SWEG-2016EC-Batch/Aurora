Design an algorithm and write a to read an employee name, weekly working hours, bonus rate per hour and
base salary and find the employees gross-salary, net salary and bonus payment. (Hint: pension rate – 5%,
tax: 15%).

#include<iostream>
using namespace std;
int main (){
    string name;
    float base_salary,weekly_working_hour;
    float tax,pension,bouns_rate,gross_salary,net_salary,bouns;
    cout<<"Please enter your name : "<<endl;
    cin>>name;
    cout<<"Please enter base salary : "<<endl;
    cin>>base_salary;

    cout<<"Please enter bouns rate per hour : "<<endl;
    cin>>bouns_rate;

    cout<<"Please enter weekly working hour : "<<endl;
    cin>>weekly_working_hour;

    bouns=bouns_rate*weekly_working_hour;
    gross_salary=base_salary+bouns;
    tax=0.15*gross_salary;
    pension=0.5*base_salary;
    net_salary=gross_salary-tax-pension;


    cout<<"The net salary of " <<name <<"  "<<net_salary<<endl;
    cout<<"The bouns of "<<name<<" "<<bouns<<endl;
    cout<<"The gross salary of "<<name<<"  "<<gross_salary<<endl;


    return  0;
}
