/*A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long
it will take to send a file, given the file size. Test your program on a 400MB (419,430,400 byte) file which may
take days.*/
#include <iostream>
using namespace std;
int main(){
double size,second,time_in_second ,time_in_hour, time_in_day;
cout<<"enter the size of file you want to transmit in mega byte "<<endl;
cin>>size;
    /* 690 character in second means one character have 1Byte so we can transfer 690 bite per second. 
    when we convert in to mega bite we divide by 1,000,000  it become 0.00096MB per second. */
    time_in_second=size/0.00096;
   /* 1 second =0.00096MB
    required time=size given ,
        to get the required time =size given*1 second/0.00096MB*/
time_in_hour=time_in_second/3600;
    //to convert in to hour we divide by 3600 because 1second =3600hour
time_in_day=time_in_hour/24;
    //to covert in a day we divide by 24 because 1day=24 hour
cout<<"the time to take transmit "<<size<<"MB "<<endl;
cout<<"in second  is  "<<time_in_second<<" seconds"<<endl;
cout<<"in hour  is  "<<time_in_hour<<" hours"<<endl;
cout<<"in day  is  "<<time_in_day<<" days"<<endl;

   /* then when we check for 400MB we get
    400
the time to take transmit 400MB is
in second416667 seconds
in hour115.741 hours
in day4.82253 days */
    
    return 0;
}
