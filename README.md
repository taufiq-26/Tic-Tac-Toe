# Tic-Tac-Toe

This is a simple text-based Tic Tac Toe game where two players can play against each other, input their moves, and track scores throughout multiple rounds. The game features the following:

Two-player gameplay: Players take turns entering their moves (X or O) to fill a 3x3 grid.

Win Check: The game checks for a winner after each move.

Draw Check: The game detects if the game ends in a draw.

Score Tracking: Keeps track of wins for each player and the number of draws.

Replay Option: After each round, players are asked if they want to play again.

Features
Board Display: The board is displayed after every move, showing the current state of the game.

Turn-based Gameplay: Players alternate between entering their moves (X or O).

Player Names: Players can enter their names before starting the game.

Win and Draw Conditions: The game checks if either player wins or if the game ends in a draw.

Scoreboard: Displays the number of wins for each player and the number of draws.

How to Play
Start the Game: Players will be asked to enter their names.

Player Turns: Players take turns entering a number between 1-9 to place their token ('X' or 'O') on the grid.

Winning: The game checks if any player has won after each move. A player wins if they have three of their tokens in a row, column, or diagonal.

Draw: If the grid is full and no one has won, the game ends in a draw.

Repeat or Exit: After a round, the score is displayed, and players can choose to play again or exit the game.

Code Overview
Global Variables:
space[3][3]: A 3x3 array representing the Tic Tac Toe grid.

token: Stores the current player's token ('X' or 'O').

tie: Boolean flag to check if the game ends in a tie.

n1, n2: Strings to store the names of Player 1 and Player 2.

score1, score2, draws: Integers to keep track of the scores for Player 1, Player 2, and the number of draws.

Functions:
functionOne(): Displays the current state of the Tic Tac Toe board.

functionTwo(): Prompts the current player to enter a move, validates the input, and updates the board.

functionThree(): Checks if there is a winner on the board.

checkDraw(): Checks if the game is a draw (i.e., the board is full and there is no winner).

resetBoard(): Resets the board for a new game.

Main Logic:
Game Loop: The main loop runs until the player chooses to exit. Inside the loop, the game resets the board, prompts players to take turns, checks for a winner or draw, and updates the scoreboard.

The scoreboard displays:

The number of wins for Player 1 and Player 2.

The number of draws.

