#include<iostream>
using namespace std;
int main(){
   char chart='A';
   for (int i = 1; i <=24; i++)
   {
     cout<<chart;
     chart++;
     if((i%6==0))
     cout<<endl;
   }
   
    return 0 ;
}
