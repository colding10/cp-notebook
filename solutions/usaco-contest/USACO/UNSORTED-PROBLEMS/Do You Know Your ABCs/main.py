ints = sorted(list(map(int, input().split())))
a, b = ints[:2]
c = ints[-1]-a-b
print(a, b, c)
