from typing import List, Set

n, m = map(int, input().split())

forward_graph = [[] for _ in range(n)]
reverse_graph = [[] for _ in range(n)]

for _ in range(m):
	a, b = map(int, input().split())
	forward_graph[a - 1].append(b - 1)
	reverse_graph[b - 1].append(a - 1)


def dfs(graph: List[List[int]]) -> Set[int]:
	"""
	Performs a depth-first traversal of a graph starting from node 0. Removes
	each node reached from a set of all nodes. Once complete, the set will only
	contain unvisited nodes and is then returned.

	:param graph: An adjacency list representing a graph.
	:return: A set containing all unvisited nodes in the depth-first traversal.
	"""
	unvisited = set(range(1, n))
	stack = [0]
	while stack:
		curr = stack.pop()

		for adj in graph[curr]:
			if adj in unvisited:
				stack.append(adj)
				unvisited.remove(adj)

	return unvisited


# These will be empty if there are no unvisited nodes
unvisited_fwd = dfs(forward_graph)
unvisited_rev = dfs(reverse_graph)

if unvisited_fwd:
	print('NO')
	print(f'1 {unvisited_fwd.pop() + 1}')
elif unvisited_rev:
	print('NO')
	print(f'{unvisited_rev.pop() + 1} 1')
else:
	print('YES')
