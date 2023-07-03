n, m = map(int, input().split())
towers = set(tuple(map(int, input().split())) for _ in range(n))
people = list(map(int, input().split()))

# print(towers)
# print(people)

for p in people:
    l = 0
    for t in towers:
        n = max(0,t[1] - abs(t[0]-p))
        l = max(l, n)
    print(l)