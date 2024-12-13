#include<iostream>
using namespace std;
int main (){
    int n=6;
    for (int i=1;i<=n;i++){
        for (int k=n-i;k>0;k--){
            cout <<" ";
        }
        for (int j=1;j<=i;j++){
            if (i==n||j==i||j==1){
               cout <<"* ";
            }
            else{
                cout <<"  ";
            }
        }
        cout<<endl;
    }
   return 0;
}
