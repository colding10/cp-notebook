with open('input.txt', 'r') as file:
    grid = [list(line.strip()) for line in file.readlines()]

i_n, j_n = len(grid), len(grid[0])

start, end = [
    next((i, j) for i in range(i_n) for j in range(j_n) if grid[i][j] == c)
    for c in ("S", "E")
]


def neighbours(i, j):
    return {
        (i0, j0)
        for i0, j0 in [(i, j+1), (i, j-1), (i+1, j), (i-1, j)]
        if i_n > i0 >= 0 <= j0 < j_n and grid[i0][j0] != "#"
    }


pos, history = start, [start]
while pos != end:
    pos = (neighbours(*pos) - set(history[-2:])).pop()
    history.append(pos)

skips = [
    (abs(i1 - i0) + abs(j1 - j0), m)
    for n, (i0, j0) in enumerate(history)
    for m, (i1, j1) in enumerate(history[n + 102 :])
]

print(sum(d == 2 for d, _ in skips))
print(sum(d <= min(20, m + 2) for d, m in skips))

