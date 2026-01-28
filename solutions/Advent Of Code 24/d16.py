import heapq

lines = open('input.txt','r').readlines()
grid = [[c for c in line] for line in lines]
C = len(grid[0])
R = len(grid)

DIRS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

dx, dy = 1, 0
for y, line in enumerate(grid):
    for x, c in enumerate(line):
        if c == "S":
            sx, sy = x, y
        if c == "E":
            ex, ey = x, y


# returns the cost and positions of the shortest path from sx, sy to ex, ey
def dijkstra(grid, sx, sy, ex, ey):
    q = [(0, sx, sy, 1, 0, {(sx, sy)})]
    seen = set()
    while len(q) > 0:
        d, x, y, dx, dy, path = heapq.heappop(q)
        if (x, y) in seen:
            continue
        seen.add((x, y))

        if (x, y) == (ex, ey):
            return d, path

        for ddx, ddy in DIRS:
            if ddx == -dx and ddy == -dy:
                continue
            nx, ny = x + ddx, y + ddy
            is_straight = abs(ddx) == abs(dx) and abs(ddy) == abs(dy)
            cost = 1
            if not is_straight:
                cost += 1000

            if grid[ny][nx] == "#" or (nx, ny) in seen:
                continue

            new_path = path.copy()
            new_path.add((nx, ny))
            heapq.heappush(q, (d + cost, nx, ny, ddx, ddy, new_path))

    return None, None


lowest, path = dijkstra(grid, sx, sy, ex, ey)
spots = set()
spots.update(path)

# for each position along the path, replace it with a wall and try dijkstra again
for px, py in path:
    if (px, py) == (ex, ey) or (px, py) == (sx, sy):
        continue

    grid[py][px] = "#"
    cost, p = dijkstra(grid, sx, sy, ex, ey)
    if cost == lowest:
        spots.update(p)
    grid[py][px] = "."

print(len(spots))
