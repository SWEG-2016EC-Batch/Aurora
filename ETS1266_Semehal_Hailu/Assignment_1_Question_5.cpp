A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long
it will take to send a file, given the file size. Test your program on a 400MB (419,430,400 byte) file which may
take days.
#include<iostream>
using namespace std;
int main (){
    double size;
    double hour;
    cout<<"Please enter the size of the file you want to transmit in mega byte : "<<endl;
    cin>>size;
    hour=size/0.00096;
    double timeinhour=hour/3600;
    double timeinday=timeinhour/24;
    cout <<"The time is take to transmite "<<size<<" mega byte is "<<endl;
    cout<<"Time in second = "<<hour<<endl;
    cout<<"Time in hour = "<<timeinhour<<endl;
    cout<<"Ime in day = "<<timeinday<<endl;
    return  0;
}
