import sys

sys.stdin = open('shell.in', 'r')
sys.stdout = open('shell.out', 'w')

lines = (list(map(int, line.replace('\n', '').split())) for line in sys.stdin.readlines() if line.count(' '))

counts = [0, 0, 0]
cups = [1, 2, 3]

for line in lines:
    guess = line.pop(-1)
    
    cups[line[0] - 1], cups[line[1] - 1] = cups[line[1] - 1], cups[line[0] - 1]
    
    if cups[guess - 1] == 3:
        counts[2] += 1
    elif cups[guess - 1] == 2:
        counts[1] += 1
    elif cups[guess - 1] == 1:
        counts[0] += 1

print(max(counts))