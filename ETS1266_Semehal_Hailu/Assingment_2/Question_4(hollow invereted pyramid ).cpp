#include<iostream>
using namespace std;
int main (){
    int n = 6;
    for (int i = 1; i <= n ; i++){
        for (int j = 0 ;j <= (n-i) ;j++){
           if (i==1 ||j == (n-i)|| j == 0){
                cout <<"*"<<" ";
            }
            else{
           
                cout <<"  ";
            }
            
        }
            cout <<endl;
        
    }
    
   return 0;
}
