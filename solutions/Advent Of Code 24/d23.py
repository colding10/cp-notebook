# Read the input from a file
with open("input.txt", "r") as f:
    edges = [line.strip().split('-') for line in f.readlines()]

# Build an adjacency list
from collections import defaultdict
graph = defaultdict(set)
for u, v in edges:
    graph[u].add(v)
    graph[v].add(u)

# Bron-Kerbosch algorithm to find cliques
def bron_kerbosch(r, p, x):
    global max_clique
    if not p and not x:
        if len(r) > len(max_clique):
            max_clique = list(r)
        return
    for node in list(p):
        bron_kerbosch(r | {node}, p & graph[node], x & graph[node])
        p.remove(node)
        x.add(node)

# Initialize variables
all_nodes = set(graph.keys())
max_clique = []

# Run Bron-Kerbosch
bron_kerbosch(set(), all_nodes, set())

# Generate the password
password = ','.join(sorted(max_clique))
print(password)