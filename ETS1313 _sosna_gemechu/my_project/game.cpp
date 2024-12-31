//project tic tac toe
#include <iostream>
#include <iomanip>
#include<window.h>
using namespace std;
int main() {
    char X,O,o,x;
    cout<<" WELCOME TO TIC TAC TOE GAME\n";
    int num;
   line : cout<<"are you ready to start ??\n";
    cout<<" Yes! click 1\n";
    cin>>num; 
    if(num==1){
goto line0;
    } else {
        cout<<"invalid input!!\n";
        goto line;
    }
    line0  :
     cout<<"\n";
    char board [3][3]={{' ',' ',' '},
                       {' ',' ',' '},   
                       {' ',' ',' '}};
    for(int i=0;i<=2;i++){
        cout<<"-------------\n";
        for(int j=0;j<=2;j++){
    cout<<"|"<<setw(3)<<board[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------"<<endl;

    for (int g=0;g<5;g++){
    for(int n=1;n<=5;n++){
    int row, column;
    line1 :
    cout<<"Player X ente row and column you want to pick star\n";
cin>>row>>column;
if(row>3||column>3){
    cout<<"invalid in put please enter valid in put\n";
 goto line1;
}
row--;
column--;
system("cls");
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
    line2 :
     cout<<"Player O ente row and column you want to pick star\n";
cin>>row>>column;
if(row>3||column>3){
    cout<<"invalid in put please enter valid in put\n";
    goto line2;
}
row--;
column--;
system("cls");
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
    for(int r=0;r<=2;r++){
            if(board[r][0]=='O'&&board[r][1]=='O'&&board[r][2]=='O'||board[0][r]=='O'&&board[1][r]=='O'&&board[2][r]=='O'){
    cout<<" dear O youu win\n";
    } else  if(board[r][0]=='X'&&board[r][1]=='X'&&board[r][2]=='X'||board[0][r]=='X'&&board[1][r]=='X'&&board[2][r]=='X') {
 cout<<" dear X youu win\n";
        } else if(board[0][0]=='X'&&board[1][2]=='X'&&board[3][3]=='X'){
            cout<<"dear X you win\n";
        } else if(board[0][0]=='O'&&board[1][2]=='O'&&board[3][3]=='O'){
            cout<<"dear O you win\n";
        } 
    }
    }
    }
    return 0;
    }
