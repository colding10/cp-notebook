from sys import stdin, stdout

n = int(stdin.readline())
rooms = [list(map(int, stdin.readline().split())) for _ in range(n)]
rooms.sort(key = lambda d: d[0])

array = []
for cust in rooms:
    start, end = cust
    if start <
