
#include <iostream>
using namespace std;
int main() {
    float basic_salary, worked_hours, bonus_rate, over_time_bonusrate;
    float gross_salary, bonus, extra_work_hours, pension, tax, net_salary;
     
    cout<<"please enter your basic salary and worked hours, "<<endl;
    cin>>basic_salary; 
    cout<<"\n worked hours";
    cin>>worked_hours;
    cout<<endl;
    if(worked_hours>40){
        cout<<"please enter over time bonus rate per hour of campany"<<endl;
        cin>>over_time_bonusrate; 
    }
    cout<<"please enter bonua rate of campany"<<endl;
    cin>>bonus_rate;
    extra_work_hours=worked_hours-40;
    bonus=extra_work_hours*bonus_rate;
    gross_salary=basic_salary+bonus;
    if(basic_salary<=200){
        tax=gross_salary*0;
    } else if(basic_salary>200&&basic_salary<=600){
        tax=gross_salary*0.1;
    }  else if(basic_salary>600&&basic_salary<=1200){
        tax=gross_salary*0.15;
    }  else if(basic_salary>1200&&basic_salary<=2000){
        tax=gross_salary*0.2;
    }  else if(basic_salary>2000&&basic_salary<=3500){
        tax=gross_salary*0.25;
    }  else if(basic_salary>3500){
        tax=gross_salary*0.3;
    }  
    pension=basic_salary*0.7;
    net_salary=gross_salary-pension-tax;
    cout<<"dear employe your gross salary  "<<gross_salary<<endl;
    cout<<"your extra work hours  "<<extra_work_hours<<" your tax is"<<tax<<endl;
    cout<<"your net total income is  "<<net_salary<<endl;
    cout<<"thank you !!"<<endl;
    
    
    

    return 0;
}
