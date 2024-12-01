#include <iostream>
using namespace std;
int main(){
float gallon, gallon_capacity, mile; 
    //first we accept the user how much fuel does his fuel tank have and how many mile the automobile can drive in full gallon of his tank 
cout<<"enter how much gallon use your automobie  to  drive 1 mile   "<<endl;
cin>>gallon_capacity;cout<<"gallon your mobile use to drive one mile "<<endl;
cout<<"How much gallon do you have in your automobile fuel tank and please enter in gallon"<<endl;
cin>>gallon;cout<<"gallon"<<endl;
        /* 1  mile  = gallon capacity
    required mile=gallon the automobile have , then to get the required mile we multiply cris cross
    required mile=gallon*1 mile/gallon capacity*/
    
mile=gallon_capacity/gallon;
cout<<"Your automobile can drive "<<mile<<"mile with out refueling Thank you!! be safe!";

    return 0;
}
