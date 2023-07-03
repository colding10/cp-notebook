n = int(input())
a = list(map(int, input().split()))
TC = int(input())

for _ in range(TC):
    i, j = map(int, input().split())
    i -= 1
    old = a[i]
    a[i] = j

    print(sum((i+1) * v for i, v in enumerate(sorted(a))))
    a[i] = old
