from sys import stdin, stdout


def floodfill(grid, x, y, number, count):
    if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] != number:
        return count
    if visited[x][y]:
        return count

    visited[x][y] = True

    count += floodfill(grid, x + 1, y, number, count)
    count += floodfill(grid, x - 1, y, number, count)
    count += floodfill(grid, x, y + 1, number, count)
    count += floodfill(grid, x, y - 1, number, count)
    
    return count


n = int(stdin.readline())
graph = [[] for _ in range(n)]
numbers = set()

for i in range(n):
    graph[i] = stdin.readline().strip().split()
    for x in graph[i]:
        numbers.add(x)

best_single = -float('inf')
best_double = -float('inf')

for x in numbers:
    visited = [[False for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if graph[i][j] == x:
                best_single = max(best_single, floodfill(graph, i, j, x, 0))

stdout.write(str(best_single) + '\n')