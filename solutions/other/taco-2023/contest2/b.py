n, m, k = map(int, input().split())
water = [list(map(int, input().split())) for _ in range(n)]

# print(water)
from sys import exit
for i in range(n-k):
    for j in range(m-k):
        x1 = i
        x2 = i+k
        y1 = j
        y2 = j+k
        
        count = 0
        for a in range(x1, x2):
            for b in range(y1, y2):
                count += water[a][b]
        if count%2 == 0:
            print('true')
            exit()
print('false')