 ## Problem Analysis

   ## Objective: 
Develop a Tic Tac Toe game that allows two players to play against each other or against the computer.
  
   ## Inputs:
• Players need to input their desired row and column numbers to place their mark.
• Input validation is necessary to ensure that players do not select occupied cells or invalid positions.

  ## Outputs:
• Display the current state of the game board after each turn.
• Announce the winner.

## Game Flow:

    * 1. Initialize the game board.
    * 2. Prompt players to choose between playing against each other or the computer.
    * 3. Alternate turns between players until a win condition is met or the board is full.
    * 4. Display the final result

## Game Rules:

     *1. Grid: The game is played on a 3x3 grid.

     *2. Players: There are two players (X and O).

     *3. Turn-taking: Players take turns placing their marks in empty cells.

     *4. Winning Condition: A player wins by aligning three of their marks horizontally, vertically, or diagonally.

     *5. Draw Condition: If all cells are filled without a winner, the game ends in draw.


## FLOW CHART

```mermaid
graph TD

 A[start]-->B[welcome]-->C[input ready? press 1]--no-->D[invalid input]-->C{input ready? press 1} --yes--> E[choose friend or computer?]-->F[choose maker X/O]--> G[intialize board 3x3]-->H[while game not over]-->I[display board]-->J[input row an column]-->K{invalid input}--yes-->J-->K{invalid input}--no-->L[update]-->M[check wins?]-->N[announce the winner] -->O[end]















