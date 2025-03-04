from sys import stdin, stdout

n = int(stdin.readline())
breeds = stdin.readline().strip()
gi = [i - 1 for i in map(int, stdin.readline().strip().split())]

cases = [] # contains all possible leader pairs (G leader, H leader)

# case 1: G leader is the first G
g_leader = breeds.index("G")
if gi[g_leader] >= breeds.rindex("G"): # only works if he covers all
    # now brute force all possible h leaders    
    for i in range(g_leader):
        if breeds[i] == "H" and gi[i] >= g_leader:
            cases.append((g_leader, i))

# case 2: H leader is the first H
h_leader = breeds.index("H")
if gi[h_leader] >= breeds.rindex("H"): # only works if he covers all
    # now brute force all possible g leaders
    for i in range(h_leader): # all indexes before
        if breeds[i] == "G" and gi[i] >= h_leader: # right type and covers the leader
            cases.append((i, h_leader))

# case 3: G leader is first G, H leader is first H
if gi[h_leader] >= breeds.rindex("H") and gi[g_leader] >= breeds.rindex("G"): # only works if all H's/G's are in respective lists
    cases.append((g_leader, h_leader))
 
ans = len(set(cases))
stdout.write(f"{ans}\n")