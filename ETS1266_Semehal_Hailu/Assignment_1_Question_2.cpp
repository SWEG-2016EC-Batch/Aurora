Write a program that prompts the capacity in gallons of an automobile fuel tank and the miles per gallons
the automobiles can be driven. The program outputs the number miles the automobile cam be driven
without refueling.
#include<iostream>
using namespace std;
int main (){
    float fuel_of_car,mile_per_gallon,mile;
    cout<<"Please enter how much mile per gallon your car takes: "<<endl;
    cin>>mile_per_gallon;
    cout<<" Please enter the amount of fuel you have in gallon : "<<endl;
    cin>>fuel_of_car;
    mile= fuel_of_car*mile_per_gallon;
    cout<<"The number miles the automobile cam be driven without refueling"<<mile<<endl;

    return  0;
}
