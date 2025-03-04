N = int(input())

print((2 ** N) - 1)

A = (list(map(str, range(N, 0, -1))), 1)
B = ([], 2)
C = ([], 3)

def move(n, source, target, auxiliary):
    if n > 0:
        # Move n - 1 disks from source to auxiliary, so they are out of the way
        move(n - 1, source, auxiliary, target)

        # Move the nth disk from source to target
        target[0].append(source[0].pop())

            
        # Display our progress
        print(source[1], target[1])
        #print(A, B, C, '##############', sep='\n')
        #print()

        # Move the n - 1 disks that we left on auxiliary onto target
        move(n - 1, auxiliary, target, source)

move(N, A, C, B)

# if N % 2:
#     a = [[1, 3], [1, 2], [3, 2]]
# else:
#     a = [[1, 2], [1, 3], [2, 3]]
# for x in range(int(((2 ** N) - 1) / 3)):
#     print('\n'.join(map(str, (' '.join(map(str, b)) for b in a))))

#     if not x % 4:
#         a[0] = [2, 1]
#     else:
#         a[0] = [1, 2]
#     if not x % 2:
#         a[1] = [3, 1]
#         a[2] = [3, 2]
#     else:
#         a[1] = [1, 3]
#         a[2] = [2, 3]