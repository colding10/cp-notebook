from sys import stdin, stdout

n = int(stdin.readline())
movies = [list(map(int, stdin.readline().strip().split())) for _ in range(n)]

movies.sort(key=lambda e: e[1])

count = 0
current_end = 0
for m in movies:
    if m[0] >= current_end:
        current_end = m[1]
        count += 1

stdout.write(f"{count}\n")
