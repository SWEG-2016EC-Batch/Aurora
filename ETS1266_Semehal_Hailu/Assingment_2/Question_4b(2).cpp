  #include<iostream>
using namespace std;
int main(){

    int row,colnums;
    cout<<"enter the number of rows : "<<endl;
    cin>>row;
    cout<<"enter the number of colnums : "<<endl;
    cin>>colnums;
    char ch='A';
    for (int j = 1; j <=colnums; j++)
    {
    for (int i = 1; i <=j; i++)
    {
        cout<<ch<<" ";
        ++ch;
    }
    cout<<""<<endl;
    ch='A';
    }
    return 0;
    }
