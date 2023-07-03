s = input().strip()
while '01' in s:
    s = s.replace('01', '')

print(len(s))
print(s)
