from sys import stdin, stdout


def get_neighbors(node):
    out = []
    x, y = node

    if y > 0:
        out.append((y - 1, x))

    if y < n - 1:
        out.append((y + 1, x))

    if x > 0:
        out.append((y, x - 1))

    if x < m - 1:
        out.append((y, x + 1))

    for i, j in out:
        if graph[i][j] == WALL:
            out.remove((i, j))

    return out


def BFS(root, target):
    queue = []  # store all nodes which are waiting to be processed
    step = 0  # number of steps neeeded from root to current node

    queue.append(root)

    # BFS
    while queue:
        step = step + 1

        size = len(queue)
        for i in range(size):
            cur = queue[0]

            if cur == target:
                return step

            for next_node in get_neighbors(cur):
                queue.append(next_node)

            queue.pop(0)

    return -1  # there is no path from root to target


WALL = 0
EMPTY = 1
START = 2
END = 3

compression = {"#": WALL, "A": START, "B": END, ".": EMPTY}

n, m = map(int, stdin.readline().split())
graph = [[EMPTY for _ in range(n)] for _ in range(m)]

for i in range(n):
    graph[i] = [compression[char] for char in stdin.readline().strip()]

starting = None
ending = None

for ri, row in enumerate(graph):
    for si, spot in enumerate(row):
        if spot == START:
            starting = (ri, si)
        elif spot == END:
            ending = (ri, si)

print(BFS(starting, ending))
