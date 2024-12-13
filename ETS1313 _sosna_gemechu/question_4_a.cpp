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
for (int i = 1; i <=row; i++)
{
cout<<i;
}
cout<<""<<endl;

return 0;
}
*/

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
row=row-(row-j);
for (int i = 1; i <=row; i++)
{
cout<<i;

}
cout<<""<<endl;

}
return 0;

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
cout<<i;

}
cout<<""<<endl;
}
return 0;

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

#include<iostream>
using namespace std;
int main(){

int row,colnums;
cout<<"enter the number of rows : "<<endl;
cin>>row;
cout<<"enter the number of colnums : "<<endl;
cin>>colnums;
char ch='a';
for (int j = 1; j <=colnums; j++)
{
for (int i = 1; i <=row; i++)
{
cout<<ch;
++ch;
}
cout<<""<<endl;
ch='a';
}
return 0;
