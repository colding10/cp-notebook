n = int(input())

def is_lucky(n):
    x = set(str(n))
    return x == {"4", "7"} or x == {"4"} or x == {"7"}

x = 0
for d in str(n):
    if is_lucky(d):
        x += 1

if is_lucky(x):
    print("YES")
else:
    print("NO")
