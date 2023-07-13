n = int(input())
heights = list(map(int, input().split()))

ans = 0

while any(heights):
    block_started = False
    for i, x in enumerate(heights):
        if x:
            block_started = True
        if x == 0 and block_started:
            ans += 1
            block_started = False
    if block_started:
        ans += 1
    for i in range(n):
        heights[i] = max(0, heights[i] - 1)

print(ans)
