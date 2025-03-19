import sys

sys.stdin = open('cowsignal.in')
sys.stdout = open('cowsignal.out', 'w')

M, N, K = map(int, input().split())
grid = [input() for _ in range(M)]

for row in grid:
    for _ in range(K):
        print(row.replace('.', '.' * K).replace('X', 'X' * K))