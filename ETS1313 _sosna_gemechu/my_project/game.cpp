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
    cout << "Yes! Click 1\n";  
    
b:  
    cin >> num;  

    // Validate the start input  
    while (cin.fail() || num != 1) {  
        cin.clear(); // Clear input error  
        cin.ignore(); // Discard invalid input  
        cout << "Invalid input! Please enter 1 to start.\n";  
        goto b;  
    }
