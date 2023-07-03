from sys import stdin, stdout

def dfs(node):
    if visited[target]:
        return
    if visited[node]:
        return False
    visited[node] = True
    if node == target:
        return
        
    for adj in graph[node]:
        dfs(adj)
        
n, m = map(int, stdin.readline().split())
graph = [[] for i in range(n+1)]

for _ in range(m):
    a, b = map(int, stdin.readline().split())
    graph[a].append(b)

for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            continue
        visited = [False for _ in range(n+1)]
        target = b
        dfs(a)
        if not visited[target]:
            print("NO")
            print(a, b)
            quit(0)

print("YES")
        
        
