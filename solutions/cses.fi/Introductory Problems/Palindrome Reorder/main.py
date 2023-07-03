s = input()

l = []

while s:
    l.append((s[0], s.count(s[0])))
    s = s.replace(s[0], '')

c = 0
for i in (i[1] % 2 for i in l):
    if i:
        c += 1
    if c > 1:
        print('NO SOLUTION') 
        quit(0)


l.sort(key = lambda x: x[1] % 2)

sl = []
for char, count in l:
    if sl:
        m = len(sl) // 2
        sl[m:m] = list(char * count)
    else:
        sl = (list(char * count))

print(''.join(sl))