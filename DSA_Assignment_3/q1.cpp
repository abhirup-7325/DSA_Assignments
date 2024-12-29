/*
Write a C program to solve the n-queens problem. The value of n may be
between 8 and 1000. We are interested in finding the first achieved solution
only. (not all the solutions)
*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void markQueen(vector<vector<int>>& board, int row, int col, int increment) {
        for (int i = 0; i < board.size(); i++) {
            board[i][col] += increment;
        }

        for (int j = 0; j < board[0].size(); j++) {
            board[row][j] += increment;
        }

        int i = row;
        int j = col;

        while (i < board.size() && j < board.size()) {
            board[i][j] += increment;
            i++;
            j++;
        }

        i = row;
        j = col;
        
        while (i >= 0 && j < board[0].size()) {
            board[i][j] += increment;
            i--;
            j++;
        }

        i = row;
        j = col;

        while (i < board.size() && j >= 0) {
            board[i][j] += increment;
            i++;
            j--;
        }

        i = row;
        j = col;

        while (i >= 0 && j >= 0) {
            board[i][j] += increment;
            i--;
            j--;
        }
    }

    void rec(vector<vector<int>>& board, int row, vector<string>& Qboard) {
        if (row >= board.size()) {
            printBoard(Qboard);
            exit(0);
        }

        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == 0) {
                Qboard[row][col] = 'Q';
                markQueen(board, row, col, 1);

                rec(board, row + 1, Qboard);

                markQueen(board, row, col, -1);
                Qboard[row][col] = '.';
            }
        }
    }

    void solveNQueens(int n) {
        vector<string> Qboard;

        string dots = "";
        for (int _ = 0; _ < n; _++) {
            dots += '.';
        }


        for (int _ = 0; _ < n; _++) {
            Qboard.push_back(dots);
        }

        vector<vector<int>> board(n, vector<int>(n, 0)); 

        rec(board, 0, Qboard);
    }

    void printBoard(vector<string> Qboard) {
        for (int i = 0; i < Qboard.size(); i++) {
            for (int j = 0; j < Qboard[i].size(); j++) {
                cout << Qboard[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
};


int main() {
    Solution solution;
    solution.solveNQueens(8);

    return 0;
}