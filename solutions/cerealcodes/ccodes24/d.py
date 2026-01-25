def create_grid(n, k):
    grid = [[0] * n for _ in range(n)]
    
    row, col = 0, 0
    while k > 0:
        grid[row][col] = 1
        k -= 1
        
        col += 1
        if col == n:
            col = 0
            row += 1
        if row == n:
            row = 0
    
    return grid

n, k = map(int, input().split())

grid = create_grid(n, k)

for row in grid:
    print("".join(map(str, row)))
