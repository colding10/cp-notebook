import sys

n = int(sys.stdin.readline())

tasks = [tuple(map(int, line.split())) for line in sys.stdin.read().split('\n') if line]

# for _ in range(n):
#     duration, deadline = map(int, sys.stdin.readline().split())
#     tasks.append((duration, deadline))

tasks.sort(key = lambda d: d[0])

score = 0
time = 0

# score = sum()
while tasks:
    task = tasks.pop(0)
    duration, deadline = task
    
    time += duration
    score += deadline - time
    
sys.stdout.write(str(score))
    