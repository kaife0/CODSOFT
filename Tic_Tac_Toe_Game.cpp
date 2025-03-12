#include <iostream>
#include <cstdlib>

using namespace std;

void printBoard(); 
int checkwin();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
 
int main()
{
    int player = 1, input, status = -1;
    char choice;

    do {
        while (status == -1)
        {
            player = (player % 2 == 0) ? 2 : 1;
            char mark = (player == 1) ? 'X' : 'O';
            cout << "Please enter Your choice for Player " << player << "(1 to 9 position on board)"<< endl;
            cin >> input;
            if (input < 1 || input > 9)
            {
                cout << "Invalid input" << endl;
                continue;
            }

            board[input] = mark;
            printBoard();

            int result = checkwin();

            if (result == 1)
            {
                cout << "Player " << player << " is the winner" << endl;
                status = 1;
            }
            else if (result == 0)
            {
                cout << "You both are smart enough." << endl;
                status = 0;
            }
            player++;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y') {
            
            for(int i = 1; i <= 9; ++i) {
                board[i] = '0' + i;
            }
            status = -1; 
        } else {
            cout << "Thanks for playing!" << endl;
        }
    } while(choice == 'y' || choice == 'Y');

    return 0;
}

void printBoard()
{
    system("cls");
    cout << "        |       |       " << endl;
    cout << "    " << board[1] << "   |   " << board[2] << "   |   " << board[3] << "   " << endl;
    cout << "||" << endl;
    cout << "        |       |       " << endl;
    cout << "    " << board[4] << "   |   " << board[5] << "   |   " << board[6] << "   " << endl;
    cout << "||" << endl;
    cout << "        |       |       " << endl;
    cout << "    " << board[7] << "   |   " << board[8] << "   |   " << board[9] << "   " << endl;
    cout << "        |       |       " << endl;
}

int checkwin()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    for (int i = 1; i < 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            continue;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}
