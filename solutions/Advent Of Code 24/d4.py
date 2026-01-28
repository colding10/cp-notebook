def count_xmas(grid, target="XMAS"):
    rows, cols = len(grid), len(grid[0])
    directions = [
        (0, 1),  # Right
        (1, 0),  # Down
        (1, 1),  # Down-right diagonal
        (1, -1), # Down-left diagonal
        (0, -1), # Left
        (-1, 0), # Up
        (-1, -1), # Up-left diagonal
        (-1, 1),  # Up-right diagonal
    ]
    count = 0
    
    def is_valid(x, y):
        return 0 <= x < rows and 0 <= y < cols
    
    for r in range(rows):
        for c in range(cols):
            for dr, dc in directions:
                x, y = r, c
                match = True
                for letter in target:
                    if not is_valid(x, y) or grid[x][y] != letter:
                        match = False
                        break
                    x += dr
                    y += dc
                if match:
                    count += 1
    return count

# Read input
with open("input.txt", "r") as f:
    grid = [line.strip() for line in f]

# Count occurrences of "XMAS"
result = count_xmas(grid)

print(f"The word 'XMAS' appears {result} times.")