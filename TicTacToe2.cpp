#include <iostream>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1 = "", n2 = "";

int score1 = 0;
int score2 = 0;
int draws = 0;

void functionOne()
{
    cout << "      |      |      \n";
    cout << "  " << space[0][0] << "   |  " << space[0][1] << "   |  " << space[0][2] << "   \n";
    cout << "______|______|______\n";
    cout << "      |      |      \n";
    cout << "  " << space[1][0] << "   |  " << space[1][1] << "   |  " << space[1][2] << "   \n";
    cout << "______|______|______\n";
    cout << "      |      |      \n";
    cout << "  " << space[2][0] << "   |  " << space[2][1] << "   |  " << space[2][2] << "   \n";
    cout << "      |      |      \n";
}

void functionTwo()
{
    int digit;
    bool validMove = false;

    while (!validMove)
    {
        if (token == 'x')
        {
            cout << n1 << " Please enter a number (1-9): ";
        }
        else
        {
            cout << n2 << " Please enter a number (1-9): ";
        }

        cin >> digit;

        if (digit < 1 || digit > 9)
        {
            cout << "Invalid input! Please choose a number between 1 and 9.\n";
            continue;
        }

        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'x' && space[row][column] != '0')
        {
            space[row][column] = token;
            token = (token == 'x') ? '0' : 'x';
            validMove = true;
        }
        else
        {
            cout << "Cell already taken! Please choose a different one.\n";
        }
    }
}

bool functionThree() // Only checks for a win
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || 
            space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || 
        space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }
    return false;
}

bool checkDraw() // New function to check draw
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (space[i][j] != 'x' && space[i][j] != '0')
                return false;
    return true;
}

void resetBoard()
{
    char val = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            space[i][j] = val++;
    token = 'x';
    tie = false;
}

int main()
{
    char playAgain;
    cout << "Enter the name of the first player: \n";
    getline(cin, n1);
    cout << "Enter the name of the second player: \n";
    getline(cin, n2);
    cout << n1 << " is player 1 and will start first\n";
    cout << n2 << " is player 2 and will start second\n";

    do
    {
        resetBoard();

        while (true)
        {
            functionOne();
            functionTwo();

            if (functionThree())
            {
                functionOne();
                if (token == 'x') {
                    cout << n2 << " Wins!\n";
                    score2++;
                } else {
                    cout << n1 << " Wins!\n";
                    score1++;
                }
                break;
            }
            else if (checkDraw())
            {
                functionOne();
                cout << "It's a Draw!\n";
                draws++;
                break;
            }
        }

        cout << "\n--- Scoreboard ---\n";
        cout << n1 << ": " << score1 << " wins\n";
        cout << n2 << ": " << score2 << " wins\n";
        cout << "Draws: " << draws << "\n";

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();
    } 
    while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
