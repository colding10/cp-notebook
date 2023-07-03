from sys import stdin, stdout

n = int(stdin.readline())
c = sorted(map(int, stdin.readline().strip().split()))

best = (0, float("inf"))

for i, v in enumerate(c):
    result = v * (n -  i)

    if result == best[0]:
        best = (result, min(v, best[1]))
        
    elif result > best[0]:
        best = (result, v)

stdout.write(f"{' '.join(map(str, best))}\n")
                    