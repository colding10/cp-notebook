import sys

board = [input().strip() for _ in range(8)]
count = 0

columns_with_queens = [0] * 8
diagonals_1 = [0] * 15
diagonals_2 = [0] * 15

def dfs(row): # place queen in row
    global count
    
    if row == 8: # placed 8 queens
        count += 1
    else: # we need to place a queen
        for column in range(8): # try all columns
            if board[row][column] == '*': # spot is blocked
                continue 
            if columns_with_queens[column]: # queen is in this column
                continue
            if diagonals_1[row + column] or diagonals_2[row - column + 7]: # queen is in this diagonal
                continue
            
            columns_with_queens[column] = diagonals_1[row + column] = diagonals_2[row - column + 7] = 1
            dfs(row + 1)
            columns_with_queens[column] = diagonals_1[row + column] = diagonals_2[row - column + 7] = 0

dfs(0)

print(count)
        