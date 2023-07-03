import sys
n, x = map(int, input().split())

def recurse(x, val, log):
    if x > n:
        if val == x:
            for i in range(n-1):
                print(f"{i}{log[i]}", end="")
            print(n)
            quit()
    
    recurse(x+1, val+x, log + ["+"])
    recurse(x+1, val-x, log + ["-"])

recurse(0, 0, [])
print('IMPOSSIBLE')
    