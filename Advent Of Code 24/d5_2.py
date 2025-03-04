from collections import defaultdict

with open('input.txt', 'r') as file:
    data = file.read()

mid = data.index("\n\n")
conditions = data[:mid].splitlines()
updates = data[mid + 2:].splitlines()

orders = defaultdict(list)
for condition in conditions:
    a, b = map(int, condition.split("|"))
    orders[a].append(b)

for key in orders:
    orders[key].sort()

out = sum(
    sorted(
        update,
        key=lambda a: sum(
            b in orders[a] for b in update if b != a
        ),
        reverse=True,
    )[len(update) // 2]
    for update in (
        list(map(int, line.split(","))) for line in updates
    )
    if any(
        any(b in orders[a] for b in update[:i])
        for i, a in enumerate(update)
    )
)

print(out)