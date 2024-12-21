#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    bool game=true;
    char X,O,o,x;
    cout<<" WELCOME TO TIC TAK TOE GAME\n";
    int num=1;
    cout<<"if you want to start click one\n";
    cin>>num; cout<<"\n";
    char board [3][3]={{'*','*','*'},{'*','*','*'},{'*','*','*'}};
    for(int i=0;i<=2;i++){
        cout<<"-------------\n";
        for(int j=0;j<=2;j++){
    cout<<"|"<<setw(3)<<board[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------"<<endl;
    while(game){
    for(int n=1;n<=5;n++){
    int row, column;
    cout<<"Player X ente row and column you want to pick star\n";
cin>>row>>column;
row--;
column--;
 for(int k=0;k<=2;k++){
        cout<<"-------------\n";
        for(int m=0;m<=2;m++){
             if(k==row&&m==column){
                cout<<"|"<<setw(3)<<"X";
board[k][m]='X';
             }
             else{
    cout<<"|"<<setw(3)<<board[k][m];
             }
             
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------\n";
     cout<<"Player O ente row and column you want to pick star\n";
cin>>row>>column;
row--;
column--;
 for(int a=0;a<=2;a++){
        cout<<"-------------\n";
        for(int s=0;s<=2;s++){
             if(a==row&&s==column){
                cout<<"|"<<setw(3)<<"O";
board[a][s]='O';
             }
             else{
    cout<<"|"<<setw(3)<<board[a][s];
             }
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------\n";
    for(int r=1;r<=2;r++){
            if(board[r][0]=='X'&&board[r][1]=='X'&&board[r][2]=='X'){
 cout<<" dear X youu win\n";
 break;
        } else if(board[r][0]=='O'&&board[r][1]=='O'&&board[r][2]=='O'){
    cout<<" dear O youu win\n";
    break;
    }
    }
    }
    }
    return 0;
    }
