from sys import stdin, stdout
from itertools import combinations_with_replacement

def beats(a, b):
    wins = 0
    losses = 0
    
    for i in range(4):
        for j in range(4):
            if a[i] > b[j]:
                wins += 1
            elif a[i] < b[j]:
                losses += 1
    
    return wins > losses

def solve(a, b):
    if beats(a, b):
        for c in combinations_with_replacement(range(1, 11), 4):
            if beats(b, c) and beats(c, a):
                return "yes"
        return "no"
    else:
        for c in combinations_with_replacement(range(1, 11), 4):
            if beats(a, c) and beats(c, b):
                return "yes"
        return "no"


t = int(stdin.readline())

for _ in range(t):
    data = tuple(map(int, stdin.readline().strip().split()))
    die_a, die_b = data[:4], data[4:]

    stdout.write(f"{solve(die_a, die_b)}\n")
