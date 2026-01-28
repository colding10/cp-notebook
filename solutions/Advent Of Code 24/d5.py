conditions = []
updates = []
with open('input.txt', 'r') as file:
    for line in file.readlines():
        line = line.strip()
        if "|" in line:
            conditions.append(list(map(int, line.split("|"))))
        elif "," in line:
            updates.append(list(map(int, line.split(","))))


out = 0
for u in updates:
    good = True
    for a, b in conditions:
        if a in u and b in u:
            if u.index(a) < u.index(b):
                pass
            else:
                good = False
                break
    if not good:
        out += u[int((len(u)-1)/2)]

print(out)
