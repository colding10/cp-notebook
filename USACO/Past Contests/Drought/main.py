from sys import stdin, stdout

def solve(cows):
    minimum_hunger = min(cows)
    deltas = [cow - minimum_hunger for cow in cows]

    if sum(deltas) % 2:
        return -1
    
    feed = 0
    while not len(set(cows)) == 1:
        maximum_hunger = max(enumerate(cows), key=lambda c: c[1])
        nearby = [maximum_hunger[0] + 1, maximum_hunger[0] - 1]
        
        maximum_nearby = (-1, -1)
        for n in nearby:
            if 0 <= n < len(cows):
                maximum_nearby = max((n, cows[n]), maximum_nearby, key=lambda c: c[1])
        
        feed += cows[maximum_nearby[0]] - minimum_hunger
        
        cows[maximum_hunger[0]] = cows[maximum_nearby[0]] - minimum_hunger
        cows[maximum_nearby[0]] = minimum_hunger
    
    return feed
        

t = int(stdin.readline().strip())

for _ in range(t):
    n = int(stdin.readline().strip())
    cows = [int(i) for i in stdin.readline().strip().split()]
    
    stdout.write(f"{solve(cows)}\n")