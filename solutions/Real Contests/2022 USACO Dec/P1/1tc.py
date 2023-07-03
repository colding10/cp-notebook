from sys import stdin, stdout

n = int(stdin.readline())
c = sorted(map(int, stdin.readline().strip().split()))

if n % 2 == 1:
    median = c[(n - 1) // 2]
    ans = median * (n + 1) // 2
    stdout.write(f"{ans} {median}\n")
else:
    median = c[(n - 2) // 2]
    ans = median * (n + 2) // 2
    stdout.write(f"{ans} {median}\n")