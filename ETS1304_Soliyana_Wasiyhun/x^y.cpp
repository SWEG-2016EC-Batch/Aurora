/*Write a program that find the result of the expression x^y where the value of X and Y are entered by the user.*/
#include <iostream>
using namespace std;
int main(){
int X, Y ,product=1; /*Starting with 1  for product is consistent with the concept of calculating the cumulative product, 
    where we begin with an identity value (1) and multiply successively by other numbers*/
cout<<"enter two integer number "<<endl; //first we accept two integer from the user 
cin>>X;
cout<<"and enter the other ";
cin>>Y;
    //we use for loop because we know how many times the X multiple by it self itrate(Y times) 
for(int i=1;i<=Y;i++){
    product*=X;
    cout<<X<<" the power of "<<Y<<" is"<<product<<endl;
}

return 0;
}
