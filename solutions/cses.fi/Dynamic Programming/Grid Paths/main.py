from sys import stdin, stdout

EMPTY = 0
TRAP = 1

n = int(stdin.readline())
graph = [[EMPTY if char == "." else TRAP for char in list(stdin.readline().strip())] for i in range(n)]
sol = [[0 for _ in range(n)] for _ in range(n)]
sol[0][0] = 1

def recurse(x, y):
    if x >= n or y >= n:
        return

    print(x, y, graph[x][y], sol[x][y])
    if graph[x][y] == TRAP:
            return
    
    up = (x-1, y)
    left = (x, y-1)

    if up[0] >= 0 and up[1] >= 0:
        sol[x][y] += sol[up[0]][up[1]]
    if left[0] >= 0 and left[1] >= 0:
        sol[x][y] += sol[left[0]][left[1]]

    recurse(x+1, y)
    recurse(x, y+1)    

recurse(0, 0)
print(sol[-1][-1])    
print(graph)
print(sol)
