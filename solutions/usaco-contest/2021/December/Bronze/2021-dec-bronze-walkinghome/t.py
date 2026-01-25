from sys import stdin, stdout

# define constants for directions
DOWN = 0
RIGHT = 1

# define a memoization table to store previously computed results
memo = {}

def solve(board, change_limit, i=0, j=0, previous=None, change_count=0):
    # check if the current position is outside the board or on a "H" cell
    if i >= len(board) or j >= len(board) or board[i][j] == "H":
        return 0

    # check if the current position is the bottom-right corner of the board
    if (i + 1, j + 1) == (len(board), len(board)):
        return 1

    # check if the current state has already been computed
    if (i, j, previous, change_count) in memo:
        return memo[(i, j, previous, change_count)]

    # if the change count exceeds the limit, return 0
    if change_count > change_limit:
        return 0

    # compute the number of paths to the bottom-right corner by moving down or right
    result = solve(
        board,
        change_limit,
        i + 1,
        j,
        DOWN,
        change_count + 1 if previous != DOWN else change_count,
    ) + solve(
        board,
        change_limit,
        i,
        j + 1,
        RIGHT,
        change_count + 1 if previous != RIGHT else change_count,
    )

    # store the result in the memoization table
    memo[(i, j, previous, change_count)] = result

    return result


# read the number of test cases from stdin
testcase_count = int(stdin.readline())

for _ in range(testcase_count):
    n, k = map(int, stdin.readline().split())
    board = [list(stdin.readline().strip()) for i in range(n)]

    stdout.write(f"{solve(board, k + 1)}\n")
    memo = {}
