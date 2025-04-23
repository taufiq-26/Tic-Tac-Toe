#include <iostream>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token = 'x';
bool tie;
string n1 = "";
string n2 = "";

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

bool functionThree()
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
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main()
{
    cout << "Enter the name of the first player : \n";
    getline(cin, n1);
    cout << "Enter the name of the second player : \n";
    getline(cin, n2);
    cout << n1 << " is player 1 so will start first \n";
    cout << n2 << " is player 2 so will start second \n";

    while (!functionThree())
    {
        functionOne();
        functionTwo();
    }

    if (token == 'x' && tie == false)
    {
        cout << n2 << " Wins" << endl;  // x just played, so 0 wins
    }
    else if (token == '0' && tie == false)
    {
        cout << n1 << " Wins" << endl;  // 0 just played, so x wins
    }
    else
    {
        cout << "It is a Draw" << endl;
    }
}
