stdin = open('gymnastics.in', 'r')
stdout = open('gymnastics.out', 'w')

k, n = map(int, stdin.readline().split())

cows = list(range(1, n + 1))
data = [list(map(int, stdin.readline().strip().split())) for _ in range(k)]

count = 0

for c1 in range(1, n + 1):
    for c2 in range(c1 + 1, n + 1):
        if all((row.index(c1) < row.index(c2) for row in data)):
            count += 1
        elif all((row.index(c1) > row.index(c2) for row in data)):
            count += 1

stdout.write(f"{count}\n")
