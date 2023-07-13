n, m = map(int, input().split())
grid = [(input().strip()) for _ in range(n)]


def genNeigh(i, j):
    out = []
    if i > 0:
        out.append((i - 1, j))
    if j > 0:
        out.append((i, j - 1))
    if i < n - 1:
        out.append((i + 1, j))
    if j < m - 1:
        out.append((i, j + 1))

    return out


def remChr(board, chr):
    grid = []
    for i in range(len(board)):
        grid.append(board[i].replace(chr, "."))
    return grid


def dfs(i, j, walked, board):
    if board[i][j] == ".":
        return walked
    new_board = remChr(board, board[i][j])

    best = -1
    for x, y in genNeigh(i, j):
        best = max(best, dfs(x, y, walked + 1, new_board))

    return best


print(dfs(0, 0, 0, grid))
