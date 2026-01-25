from sys import stdin, stdout
from itertools import permutations

DOWN = 0
RIGHT = 1


def solve2(board, change_limit, i=0, j=0, previous=None, change_count=0):
    if change_count > change_limit:
        return 0
    if i >= len(board) or j >= len(board):
        return 0
    if board[i][j] == "H":
        return 0
    if (i + 1, j + 1) == (len(board), len(board)):
        return 1

    return solve2(
        board,
        change_limit,
        i + 1,
        j,
        DOWN,
        change_count + 1 if previous != DOWN else change_count,
    ) + solve2(
        board,
        change_limit,
        i,
        j + 1,
        RIGHT,
        change_count + 1 if previous != RIGHT else change_count,
    )


testcase_count = int(stdin.readline())

for _ in range(testcase_count):
    n, k = map(int, stdin.readline().split())
    board = [list(stdin.readline().strip()) for i in range(n)]

    stdout.write(f"{solve2(board, k + 1)}\n")
