import sys

n, x = map(int,input().split())
numbers = [int(x) for x in input().split()]

val_to_ind = {}
for i, val in enumerate(numbers):
	if x - val in val_to_ind:
		print(i + 1, val_to_ind[x - val])
		sys.exit(0)
	val_to_ind[val] = i + 1

print("IMPOSSIBLE")