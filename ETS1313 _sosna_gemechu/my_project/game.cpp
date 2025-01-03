#include <iostream>  
#include <iomanip>  
#include <cstdlib>  
#include <ctime>  
#include <windows.h>  
using namespace std;  

int main() {  
    // Tracks the current player ('X' or 'O') and computer marker  
    char currentPlayer;  
    char computer;  

    // Display welcome message  
    cout << "WELCOME TO TIC TAC TOE GAME\n";  
    int num;  

startgame:  
    // Prompt user to start the game  
    cout << "Are you ready to start??\n";  
    cout << "Yes? please Click 1\n";  
    
b:  
    cin >> num;  

    // Validate the start input  
    while (cin.fail() || num != 1) {  
        cin.clear(); // Clear input error  
        cin.ignore(); // Discard invalid input  
        cout << "Invalid input! Please enter 1 to start.\n";  
        goto b;  
    }
int num2;  
    // Ask the user to choose the game mode  
    cout << "Do you want to play with your friend or with me??\n";  
a:  
    cout << "If you want to play with me press 1,\n if you want to play with your friend press 0\n";  
    cin >> num2;  
    while (cin.fail() || (num2 != 1 && num2 != 0)) {  
        cin.clear();  
        cin.ignore();  
        cout << "Invalid input! Please enter 1 to play with me or 0 to play with your friend.\n";  
        goto a;  
    }  

    if (num2 == 1) {  
        chooseplayer:  
        // Allow player to choose their marker (X or O)  
        cout << "Which player would you like to start as? (X/O): ";  
        cin >> currentPlayer;  
        if (currentPlayer != 'X' && currentPlayer != 'O') {  
            cout << "Invalid choice! Please choose either X or O.\n";  
            goto chooseplayer;  
        }  

        // Initialize the game board  
        char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };









