#include <iostream>

using namespace std;

typedef int direction;

int solve(char board[], int change_limit, int i, int j, direction previous, int change_count) {
    if (change_count > change_limit) {
        return 0;
    } 
    if (i >= board.size() || j >= board.size()) {
        return 0;
    }
    if (board[i][j] == 'H') {
        return 0;
    }
    if (i + 1 == board.size() || j + i == board.size()) {
        return 1;
    }

    return solve(board, change_limit, i + 1, )
}