def f(x, y, tC, tM, kC, kM):
    return x*(tC-kC) + y*(tM-kM)

def satisfied(friends, tC, tM, kC, kM, amount):
    for a, b, c in friends:
        if f(a, b, tC, tM, kC, kM) > c - amount:
            return False
    return True

def binary_search(friends, tC, tM, kC, kM):
    left, right = 0, min(tC-1, tM-1)
    while left < right:
        mid = (left + right) // 2
        if satisfied(friends, tC, tM, kC, kM, mid):
            right = mid
        else:
            left = mid + 1
    return left if satisfied(friends, tC, tM, kC, kM, left) else -1

T = int(input())
for _ in range(T):
    input()
    N, tC, tM = map(int, input().split())
    friends = []
    for _ in range(N):
        a, b, c = map(int, input().split())
        friends.append((a, b, c))
    result = binary_search(friends, tC, tM, 0, 0)
    print(result)
