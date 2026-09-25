#include<iostream>
#include<vector>
using namespace std;
int draw(vector<vector<char>>& board)
{
    cout << "Current Board: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----" << endl;
    }
    return 0;
}
int user(vector<vector<char>>& board, char player)
{
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = player;
        return 1;
    }
    else
    {
        cout << "Invalid move. Try again." << endl;
        return 0;
    }
}
int computer(vector<vector<char>>& board, char player)
{
    cout<<"Computer's turn: "<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                return 1;
            }
        }
    }
    return 0;
}
int check(vector<vector<char>>& board)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}
int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    int moves = 0;
    while (moves < 9)
    {
        draw(board);
        if (player == 'X')
        {
            if (user(board, player))
            {
                moves++;
                if (check(board))
                {
                    draw(board);
                    cout << "Player " << player << " wins!" << endl;
                    return 0;
                }
                player = 'O';
            }
        }
        else
        {
            if (computer(board, player))
            {
                moves++;
                if (check(board))
                {
                    draw(board);
                    cout << "Player " << player << " wins!" << endl;
                    return 0;
                }
                player = 'X';
            }
        }
    }
    draw(board);
    cout << "It's a draw!" << endl;
    return 0;
}