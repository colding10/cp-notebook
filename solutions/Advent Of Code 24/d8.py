from collections import defaultdict; from math import gcd; from sys import stdin

antennas = defaultdict(list)
antinodes = set()
N = 0
for i, line in enumerate(stdin):
    if N == 0: N = len(line.rstrip())
    for j, ch in enumerate(line):
        if ch != '.':
            antennas[ch].append([i,j])
M = i + 1
inside = lambda i, j: i in range(M) and j in range(N)

for k, L in antennas.items():
    for i, (i0, j0) in enumerate(L):
        for i1, j1 in L[i+1:]:
            di, dj = i1 - i0, j1 - j0           
            di, dj = di // (d := gcd(di, dj)), dj // d          
            k = 0
            while inside(pi := i0 + k*di, pj := j0 + k*dj):
                antinodes.add((pi,pj))
                k += 1
            k = -1
            while inside(pi := i0 + k*di, pj := j0 + k*dj):
                antinodes.add((pi,pj))
                k -= 1

print(len(antinodes))