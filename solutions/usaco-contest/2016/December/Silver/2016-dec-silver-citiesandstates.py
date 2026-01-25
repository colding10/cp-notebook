def index(s: str) -> int:
    ind = 0
    for c in s:
        ind = 26 * ind + (ord(c) - ord("A"))
    return ind


pairs = []
with open("citystate.in") as read:
    for _ in range(int(read.readline())):
        city, state = read.readline().strip().split()
        city = city[:2]  # We only care about the first two letters of the city
        pairs.append((city, state))

seen = [0 for _ in range(26**4)]
total = 0
for c, s in pairs:
    if c != s:
        total += seen[index(s + c)]
    seen[index(c + s)] += 1

print(total, file=open("citystate.out", "w"))
