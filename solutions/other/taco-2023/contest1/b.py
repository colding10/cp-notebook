m, n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
mine = [[False for _ in range(m)] for _ in range(n)]
safe = [[False for _ in range(m)] for _ in range(n)]
safe[0] = [True for _ in range(m)]
safe[-1] = [True for _ in range(m)]
for r in range(len(safe)):
    safe[r][0] = True
    safe[r][-1] = True
    
def neigh(x, y):
    out = []
    if x > 0:
        out.append((x - 1, y))
    if y > 0:
        out.append((x, y - 1))
    if x < n - 1:
        out.append((x + 1, y))
    if y < m - 1:
        out.append((x, y + 1))
    
    if x > 0 and y > 0:
        out.append((x - 1, y - 1))
    if x < n - 1 and y < m - 1:
        out.append((x + 1, y + 1))
    if x > 0 and y < m - 1:
        out.append((x - 1, y + 1))
    if x < n - 1 and y > 0:
        out.append((x + 1, y - 1))
    return out

def is_edge(x, y) -> bool:
    return x == 0 or y == 0 or x == n-1 or y == m-1

def possible_mine(x, y) -> int:
    out = 0
    for a, b in neigh(x, y):
        if is_edge(a, b) or safe[a][b] or mine[a][b]:
            continue
        out += 1
    
    return out

def known_mine(i, j):
    out = 0
    for a, b in neigh(i, j):
        if mine[a][b] and not (a == i and b == j):
            out += 1
    return out

def test(i, j):
    if mine[i][j]:
        return
    
    if possible_mine(i, j) == graph[i][j] - known_mine(i, j):
        for a, b in neigh(i, j):
            if is_edge(a, b) or safe[a][b]:
                continue
            mine[a][b] = True
    elif possible_mine(i, j) == 0:
        for a, b in neigh(i, j):
            if mine[a][b] or is_edge(a, b):
                safe[a][b] = True

for _ in range(2):
    for i in range(n):  
        for j in range(m):  
            test(i, j)


        
for i, r in enumerate(mine):
    for j, v in enumerate(r):
        if v:
            print(i, j)
