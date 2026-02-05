"""
ID: colindi1
LANG: PYTHON3
TASK: beads
"""

# find all possible cuts and add the other part of necklace for being able to loop
# go through all possible combinations
# get maximum number of beads collected

with open('beads.in', 'r') as file:
    lines = [i.replace('\n', '') for i in file.readlines()]
    necklace = lines[1]
    length = int(lines[0])


ready = [False] * length
value = [0] * length


out = max(counts)
#print(out)
with open('beads.out', 'w') as file:
    file.write(str(out)+'\n')