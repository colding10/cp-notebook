import sys

def countPowerOf(n, p):
    count = 0
    
    d = n
    
    while True:
        d, r =  divmod(d, p)
        if r:
            break
        else:
            count += 1
    
    return count

n = int(sys.stdin.readline())

def solve(n):
    count = 0
    
    div = 5
    while div <= n:
        count += int(n / div)
        div *= 5
    
    return count

print(solve(n))