from math import factorial
from math import comb

def solve(n, m):
    print(comb(m + n - 1, n-1) % 1000000007)

n, m = map(int, input().split())
solve(n, m)
