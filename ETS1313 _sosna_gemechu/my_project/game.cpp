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

start_game:  
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
        if (currentPlayer != 'X' && currentPlayer != 'O'&& currentPlayer != 'x' && currentPlayer != 'o') {  
            cout << "Invalid choice! Please choose either X or O.\n";  
            goto chooseplayer;  
        }  

        // Initialize the game board  
        char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
        // Display the empty board  
        for (int i = 0; i < 3; i++) {  
            cout << "-------------\n";  
            for (int j = 0; j < 3; j++) {  
                cout << "|" << setw(3) << board[i][j];  
            }  
            cout << "|\n";  
        }  
        cout << "-------------\n";  

        // Main game loop for player vs. computer  
        for (int z = 1; z <= 5; z++) {  
            int row, column;  

        playerturn1:  
            cout << "Player " << currentPlayer << ", enter the row and column you want to pick:\n"; 
            cout<<"Row\n";
            cin >> row;
            cout<<"column\n";
            cin>>column;  
            
            while (cin.fail()) {  
                cin.clear();  
                cin.ignore();  
                cout << "Invalid input! Please enter valid input for row and column.\n";  
                goto playerturn1;  
            }  

            system("cls");  
            // Validate player input  
            if (row < 1 || row > 3 || column < 1 || column > 3 || board[row - 1][column - 1] != ' ') {  
                cout << "Invalid input! Please enter a valid input.\n";  
                goto playerturn1;  
            }  

            // Update the board with player's marker  
            row--;  
            column--;  
            board[row][column] = currentPlayer;
// Display updated board  
            for (int i = 0; i < 3; i++) {  
                cout << "-------------\n";  
                for (int j = 0; j < 3; j++) {  
                    cout << "|" << setw(3) << board[i][j];  
                }  
                cout << "|\n";  
            }  
            cout << "-------------\n";  

            // Check win conditions for player  
            for (int r = 0; r < 3; r++) {  
                if ((board[r][0] == currentPlayer && board[r][1] == currentPlayer && board[r][2] == currentPlayer)||   
                    (board[0][r] == currentPlayer && board[1][r] == currentPlayer && board[2][r] == currentPlayer)) {  
                    cout << "Dear " << currentPlayer << ", you win!\n";  
                    goto endgame;  
                }  
            }  
            if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)||   
                (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {  
                cout << "Dear " << currentPlayer << ", you win!\n";  
                goto endgame;  
            }
            // Computer's turn logic  
            if (currentPlayer == 'X') {  
                computer = 'O';  
            } else {  
                computer = 'X';  
            }  

            // Randomized computer move  
            int randomRows = rand() % 3;  
            int randomCols = rand() % 3;  

            while (board[randomRows][randomCols] != ' ') {  
                randomRows = rand() % 3;  
                randomCols = rand() % 3;  
            }  
            board[randomRows][randomCols] = computer;  
            cout << "\nComputer's move:\n";  
            Sleep(3);  
            
            // Display updated board after computer's move  
            for (int i = 0; i < 3; i++) {  
                cout << "-------------\n";  
                for (int j = 0; j < 3; j++) {  
                    cout << "|" << setw(3) << board[i][j];  
                }  
                cout << "|\n";  
            }  
            cout << "-------------\n";  
        }  
    }      else  if(num2==0){
         choose: cout << "Which letter would you like to use as a marker? (X/O): ";
    cin >> currentPlayer; 
    
    // to let the user use both uppercase and lowercase letter 
    if (currentPlayer != 'X' && currentPlayer != 'O' && currentPlayer != 'x' && currentPlayer != 'o') {
        cout << "Invalid choice! Please choose either X or O.\n";
        goto choose;
    } else{

    cout << "\n";
    char board[3][3] = { {' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '} }; // Initialize empty board

    // Display the initial empty board
    for (int i = 0; i < 3; i++) {
        cout << "-------------\n";
        for (int j = 0; j < 3; j++) {
            cout << "|" << setw(3) << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "-------------\n";

    // Main game loop for multiple rounds
    while (true) {
        int row, column;

        // Prompt the current player for their turn
playerturn:
        cout << "Player " << currentPlayer << ", enter the row and column you want to pick:\n";
        cout<<"Row\n";
        cin >> row;
        cout<<"column\n";
        cin>>column;
 while (cin.fail()||row > 3  ||column > 3 || row < 1 || column < 1 || board[row - 1][column - 1] != ' ') {
     cin.clear(); // clear the error flag 
   cin.ignore(); 
   // discard invalid input
    cout << "Invalid input! Please enter valid in put\n";
    goto playerturn;
    }

        // Update the board with the current player's marker
        row--;
        column--;
        board[row][column] = currentPlayer;

        //  for Clearing the previous table and display the updated board.
        system("cls");
        for (int i = 0; i < 3; i++) {
            cout << "-------------\n";
            for (int j = 0; j < 3; j++) {
                cout << "|" << setw(3) << board[i][j];
            }
            cout << "|" << endl;
        }
        cout << "-------------\n";

        // Check for win conditions immediately after the current player's move
        for (int r = 0; r < 3; r++) {
            if ((board[r][0] == currentPlayer && board[r][1] == currentPlayer && board[r][2] == currentPlayer)|| 
                (board[0][r] == currentPlayer && board[1][r] == currentPlayer && board[2][r] == currentPlayer)) {
                // Current player wins
                cout << "Dear " << currentPlayer << ", you win!\n";
                goto endgame;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            // Current player wins diagonally
            cout << "Dear " << currentPlayer << ", you win!\n";
            goto endgame;
        }

        // Switch the current player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
   }}
    

endgame:  
    // Prompt for game restart  
    char ctrl;  
    cout << "Do you want to restart? If yes, please press y." << endl;  
    cin >> ctrl;  
    if (ctrl == 'y' || ctrl == 'Y') {  
        goto start_game;  
    } else {  
        cout << "The game is over! THANK YOU." << endl;  
    }  

    return 0;  
}







