//
// Created by janeuler on 2024/8/11.
//
# include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); j++) {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }
        for (auto &x: board) {
            for (auto &y: x) {
                if (y == 'O') y = 'X';
                if (y == 'T') y = 'O';
            }
        }
    }

private:
    void dfs(std::vector<std::vector<char> > &board, int curx, int cury) {
        if (curx < 0 || curx >= board.size() || cury < 0 || cury >= board[0].size()) return;

        if (board[curx][cury] == 'O') {
            board[curx][cury] = 'T';

            dfs(board, curx + 1, cury);
            dfs(board, curx - 1, cury);
            dfs(board, curx, cury + 1);
            dfs(board, curx, cury - 1);
        }
    }
};
