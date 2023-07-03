# import sys

# N = 5#int(sys.stdin.readline().strip())
# P = [1, 5, 10, 3, 4]#list(map(int, sys.stdin.readline().split(' ')))
# C = [1, 2, 2, 2, 1]#list(map(int, sys.stdin.readline().split(' ')))

# D = [P[i] - C[i] for i in range(N)]

# commands = 0
# while True:
#     if not any(D):
#         break
    
#     to_change_indexes = []

#     i = 0
#     starting = D[i]
#     while starting == 0:
#         i += 1
#         starting = D[i]
    
#     to_change_indexes.append(i)

#     if starting > 0:
#         for j in range(i, N):
#             if D[j] > 0:
#                 to_change_indexes.append(j)
#             else:
#                 break
    
#     else:
#         for j in range(i, N):
#             if D[j] < 0:
#                 to_change_indexes.append(j)
#             else:
#                 break
    
#     for i in set(to_change_indexes):
#         D[i] += (1 if starting < 0 else -1)

#     commands += 1

# print(commands)

### after
N = int(input())
P = list(map(int,input().split()))
T = list(map(int,input().split()))
 
difs = [x-y for x,y in zip(P,T)]
print(sum(abs(x-y) for x,y in zip(difs+[0],[0]+difs))//2)