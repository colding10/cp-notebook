import sys

sys.stdin = open('paint.in', 'r')
sys.stdout = open('paint.out', 'w')

a = list(map(int, input().split()))
b = list(map(int, input().split()))

painted = set(list(range(*a)) + list(range(*b)))

print(len(painted))