from math import ceil, sqrt
import math



def solve():
    n, k = map(int, input().split())
    if k == 0:
        print(0)
        return
    partnerships = []
    parallel_count = {}
    
    crossing = 0
    side = 0

    for _ in range(k):
        a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        
        if abs(a-b) == 1:
            side += 1
        else:
            crossing += 1
    x = n/2
    # print(crossing, side)
    if crossing > side:
        print(int(x-crossing))
    else:
        print(int(x-side))

t = int(input())
for _ in range(t):
    solve()
