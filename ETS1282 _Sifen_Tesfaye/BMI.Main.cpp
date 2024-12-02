/*Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is
in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to
work for multiple person .*/


#include<iostream>
using namespace std;
int main(){
    float weight,height,BMI,choice;
    do
    {
     cout<<"Please enter your weight : "<<endl;
    cin>>weight;
    cout<<"Please enter your height : "<<endl;
    cin>>height;
    BMI=weight/ (height* height);
    cout<<"BMI = "<<BMI<<endl;
      if (BMI<18.5)
      {
        cout<<"underweight"<<endl;
    }else if (BMI>18.5 && BMI<24.9)
    {
        cout<<"normal weight"<<endl;
    }else if (BMI<25 && BMI >29.9)
    {
        cout<<"overweight"<<endl;
    }else{
        cout<<"obese"<<endl;
    } 
    cout<<"Do you want to continue if so press 1 if not press 0"<<endl;
    cin>>choice;
    }
    while (choice=='0');
    cout<<"we finish thank you";
      return 0;
}





  
