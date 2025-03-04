import itertools


l = list(input().strip())

perms = sorted(set((''.join(i) for i in itertools.permutations(l, len(l)))))

print(len(perms))
print('\n'.join(perms))
