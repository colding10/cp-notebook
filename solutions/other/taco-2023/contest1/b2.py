def find_mines(m, n, grid):
    mines = []
    
    for i in range(1, m-1):
        for j in range(1, n-1):
            if grid[i][j] > 0:
                mines.append((i, j))
    
    return mines

# Read input
m, n = map(int, input().split())
grid = []
for _ in range(m):
    row = list(map(int, input().split()))
    grid.append(row)

# Find mines
mines = find_mines(m, n, grid)

# Output the positions of the mines
if len(mines) > 0:
    for mine in mines:
        print(mine[0], mine[1])
else:
    print(0)
