import sys

sys.stdin = open('shuffle.in', 'r')
sys.stdout = open('shuffle.out', 'w')

N = int(input())
A = list(map(int, input().split()))
cows = input().split()

A = [i - 1 for i in A]

def undo(cows):
    return [cows[i] for i in A]

for _ in range(3):
    cows = undo(cows)

print("\n".join(cows))
