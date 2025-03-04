def solve():
    n, m = map(int, input().strip().split())
    grid = [list(input().strip()) for _ in range(n)]
    # print(grid)
    flips_pattern1 = 0
    flips_pattern2 = 0

    for i in range(n):
        for j in range(m):
            expected_value_pattern1 = (i + j) % 2
            expected_value_pattern2 = 1 - expected_value_pattern1
            actual_value = int(grid[i][j])

            if actual_value != expected_value_pattern1:
                flips_pattern1 += 1
            if actual_value != expected_value_pattern2:
                flips_pattern2 += 1

    print(min(flips_pattern1, flips_pattern2))


t = int(input().strip())
for _ in range(t):
    solve()
