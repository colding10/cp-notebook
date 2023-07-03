# USACO 2017 Dec Bronze
# Prob 3. Milk Measurement

# FULLY AC

fin = open("measurement.in", "r")
fout = open("measurement.out", "w")

outputs = {name: 7 for name in ("Bessie", "Elsie", "Mildred")}

N = int(fin.readline())

entries = [line.strip().split() for line in fin.readlines()]
entries = [(int(line[0]), line[1], int(line[2])) for line in entries]

entries.sort(key = lambda e: e[0])

display_changes = 0
bests = [outputs.keys()]
for day, name, change in entries:
    outputs[name] += change
    new_best = max(outputs.values())
    new_best_cows = sorted([cow[0] for cow in outputs.items() if cow[1] == new_best])

    if new_best_cows != bests:
        display_changes += 1
        bests = list(new_best_cows)

fout.write(f"{display_changes}\n")
fout.close()
