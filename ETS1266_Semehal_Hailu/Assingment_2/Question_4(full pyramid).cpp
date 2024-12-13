
   #include<iostream>
using namespace std;
int main(){
    int row,colnums;
    cout<<"enter the number of rows : "<<endl;
    cin>>row;
    cout<<"enter the number of colnums : "<<endl;
    cin>>colnums;
    for (int j = 1; j <=colnums; j++)
    {
        int z=5-j;
        row=row-(row-j);
        for(int k=1; k<=z;k++){
        cout<<" ";
        
        }
    for (int i = row; i >=1; i--)
    {
        cout<<"*"<<" ";
        
    }
    cout<<""<<endl;
    }
    return 0;}
