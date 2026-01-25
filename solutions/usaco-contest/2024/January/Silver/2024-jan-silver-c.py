n = int(input())
a = list(map(int, input().split()))

ans = 0
for L in range(1, max(a) + 1):
    mods = set()
    for ai in a:
        mods.add(ai % L)
    if len(mods) <= 3 and all(ai >= 4 * L for ai in a):
        ans += L * (n - len(mods) + 1)

print(ans)
