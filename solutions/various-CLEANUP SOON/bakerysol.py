# Bakery
from math import floor, ceil


class Customer:
    def __init__(self, cookie, muffin, wait_time):
        self.cookie, self.muffin, self.wait_time = cookie, muffin, wait_time


def solution():
    input()
    N, tC, tM = map(int, input().split())
    cows = []
    for _ in range(N):
        a, b, c = map(int, input().split())
        cows.append(Customer(a, b, c))
    l, r = 2, tC + tM
    while l < r:
        mid = (l + r + 1) // 2
        up, low = min(tC, mid - 1), max(mid - tM, 1)
        for cow in cows:
            if cow.cookie == cow.muffin:
                if cow.wait_time < cow.muffin * mid:
                    up = float("-inf")
            else:
                limit = (cow.wait_time - cow.muffin * mid) / (cow.cookie - cow.muffin)
                if cow.cookie > cow.muffin:
                    up = min(floor(limit), up)
                else:
                    low = max(ceil(limit), low)
        if up >= low:
            l = mid
        else:
            r = mid - 1
    ans = tC + tM - l
    print(ans)


T = int(input())
for _ in range(T):
    solution()