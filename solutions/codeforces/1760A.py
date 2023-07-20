t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    x = sorted([a, b, c])
    print(x[1])
