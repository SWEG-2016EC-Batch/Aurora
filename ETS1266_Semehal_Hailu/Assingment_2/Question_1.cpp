#include<iostream>
using namespace std;
int main(){
    int basic_salary,worked_hours,bonus=0,extra_work_hours,gross_salary;
    float bonus_rate,tax,pension,net_salary;
    cout<<"enter basic salary please : "<<endl;
    cin>>basic_salary;
    cout<<"enter worked hour please : "<<endl;
    cin>>worked_hours;
    if (worked_hours>40)
    {
        cout<<"please enter over time bonus rate : "<<endl;
        cin>>bonus_rate;
        extra_work_hours=worked_hours-40;
        bonus=extra_work_hours*bonus_rate;
    }
    gross_salary=basic_salary+bonus;
    pension=0.7*basic_salary;
    if (gross_salary<200)
    {
        tax=0;
    }else if (gross_salary<600 && gross_salary>200)
    {
        tax=0.1*gross_salary;
    }else if (gross_salary<1200 && gross_salary>600)
    {
        tax=0.15*gross_salary;
    }else if (gross_salary<2000 && gross_salary>1200)
    {
        tax=0.2*gross_salary;
    }else if (gross_salary<3500 && gross_salary>2000)
    {
      tax=0.25*gross_salary;
    }else{
        tax=0.3*gross_salary;
    }
    
    net_salary=gross_salary-pension-tax;
     
     cout<<"net salary = "<<net_salary<<endl;    
   
    return 0;
}
