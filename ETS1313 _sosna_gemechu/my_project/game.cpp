#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    int game = 1;  // Tracks the number of games played
    char currentPlayer; // Tracks the current player ('X' or 'O')

    // Welcome message
    cout << "WELCOME TO TIC TAC TOE GAME\n";
    int num;

start_game:
    // Prompt player to start the game
    cout << "Are you ready to start??\n";
    cout << "Yes! Click 1\n";
    cin >> num;

    if (num != 1) {
        // Handle invalid input
        cout << "Invalid input!!\n";
        goto start_game;
    }

choose_player:
    // Ask the player to choose their marker (X or O)
    cout << "Which player would you like to start as? (X/O): ";
    cin >> currentPlayer; 
    
    // to let the user use both uppercase and lowercase letter 
    if (currentPlayer != 'X' && currentPlayer != 'O' && currentPlayer != 'x' && currentPlayer != 'o') {
        cout << "Invalid choice! Please choose either X or O.\n";
        goto choose_player;
    }

    cout << "\n";
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }; // Initialize empty board

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
player_turn:
        cout << "Player " << currentPlayer << ", enter the row and column you want to pick:\n";
        cin >> row >> column;

        // Validate input
        if (row > 3 || column > 3 || row < 1 || column < 1 || board[row - 1][column - 1] != ' ') {
            cout << "Invalid input! Please enter a valid input.\n";
            goto player_turn;
        }

        // Update the board with the current player's marker
        row--;
        column--;
        board[row][column] = currentPlayer;

        // Clear screen and display updated board
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
            if ((board[r][0] == currentPlayer && board[r][1] == currentPlayer && board[r][2] == currentPlayer) ||
                (board[0][r] == currentPlayer && board[1][r] == currentPlayer && board[2][r] == currentPlayer)) {
                // Current player wins
                cout << "Dear " << currentPlayer << ", you win!\n";
                goto end_game;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            // Current player wins diagonally
            cout << "Dear " << currentPlayer << ", you win!\n";
            goto end_game;
        }

        // Switch the current player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

end_game:
    // Display end of game message
    cout << "The game is over! THANK YOU." << endl;
    return 0;
}
