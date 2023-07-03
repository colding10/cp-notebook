s = input().strip()

u_count = 0
l_count = 0

for c in s:
    if c.isupper():
        u_count += 1
    else:
        l_count += 1

if u_count > l_count:
    print(s.upper())
else:
    print(s.lower())
