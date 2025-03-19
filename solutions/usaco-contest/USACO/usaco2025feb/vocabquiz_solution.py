N = int(input())
P = [0] + list(map(int, input().split()))
num_child = [0] * (N+1)
length = [0]*(N+1)
for i in range(1,N+1):
    length[i] = length[P[i]]+1
    num_child[P[i]] += 1
 
M = sum(x == 0 for x in num_child)
for _ in range(M):
    x = int(input())
    while True:
        assert num_child[x] == 0
        if x == 0:
            print(0)
            break
        if num_child[P[x]] == 1:
            x = P[x]
            num_child[x] = 0
            continue
        print(length[x])
        num_child[P[x]] -= 1
        break