from sys import stdin, stdout

n = int(stdin.readline())
ranges = [range(*map(int, stdin.readline().split())) for _ in range(n)]

l1 = ["0" for _ in range(n)]
l2 = ["0" for _ in range(n)]

for r1 in range(len(ranges)):
    for r2 in range(len(ranges)):
        if r1 == r2:
            continue
        if ranges[r1] in ranges[r2]:
            l1[r2] = "1"
            l2[r1] = "1"
        if ranges[r2] in ranges[r1]:
            l1[r1] = "1"
            l2[r2] = "1"

l1 = " ".join(l1)
l2 = " ".join(l2)

stdout.write(f"{l1}\n{l2}\n")
