from sys import stdin, stdout

DOWN = "R"
RIGHT = "D"


class Cow:
    startX: int
    startY: int

    cost: int
    traveled: list = []

    def __init__(self, sX, sY, graph, n):
        self.startX = sX
        self.startY = sY

        while sX != n and sY != n:
            self.traveled.append((sX, sY))

            direction = graph[sX][sY]
            if direction == DOWN:
                sY += 1
            else:
                sX += 1

        self.cost = graph[sX][sY]

    # def __repr__(self):
    #     return f"Cow({self.startX=}, {self.startY=}, {self.cost=})"


n = int(stdin.readline())
graph = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(n):
    directions, cost = stdin.readline().strip().split()

    graph[i][:-1] = list(directions)
    graph[i][-1] = int(cost)

graph[-1] = list(map(int, stdin.readline().strip().split())) + [0]
t = int(stdin.readline().strip())

cows = []

for i in range(n):
    for j in range(n):
        if (i, j) == (n + 1, n + 1):
            continue

        c = Cow(i, j, graph, n)
        cows.append(c)

cost = sum((c.cost for c in cows))

for _ in range(t):
    # print(cows)
    # print(graph)
    
    x, y = map(int, stdin.readline().strip().split())
    x -= 1
    y -= 1
    
    graph[x][y] = ("D" if graph[x][y] == "R" else "R")
    
    coord = (x, y)
    
    stdout.write(f"{cost}\n")
    delta = 0
    
    new_cows = cows.copy()
    
    for ci, c in enumerate(cows):
        if coord in c.traveled:
            prev = c.cost
            new_cows[ci] = Cow(c.startX, c.startY, graph, n)
            after = new_cows[ci].cost
            
            change = after - prev
            delta += change
    
    cows = new_cows
    
    cost += delta
    
stdout.write(f"{cost}\n")