# read input values
C, N = map(int, input().split())

# read teams as a list of bitmasks
teams = []
for i in range(N):
    bitmask = 0
    for j, cow in enumerate(input().strip()):
        if cow == 'H':
            bitmask |= (1 << j)
    teams.append(bitmask)

# calculate maximum difference for each team
for i in range(N):
    max_diff = 0
    for j in range(N):
        if i != j:
            diff = bin(teams[i] ^ teams[j]).count('1')
            max_diff = max(max_diff, diff)
    print(max_diff)
