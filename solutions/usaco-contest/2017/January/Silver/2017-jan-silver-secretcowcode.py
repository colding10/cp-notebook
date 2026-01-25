from math import log, ceil
import sys

sys.stdin = open("cowcode.in", "r")
sys.stdout = open("cowcode.out", "w")

s, n = input().strip().split()
n = int(n)

needed_reps = ceil(log(n / len(s), 2))
code = list(s)

while needed_reps:
    new = list(code)
    new.insert(0, new[-1])

    new.pop(-1)

    code += new
    needed_reps -= 1

print(code[n - 1])
