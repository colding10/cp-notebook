import itertools

with open("speeding.in") as fin:
    N, M = map(int, fin.readline().split())

    data = list(map(str.split, fin.readlines()))
    limit_data = [[int(num) for num in line] for line in data[:N]]
    bessie_data = [[int(num) for num in line] for line in data[N:]]

    if len(limit_data) != N or len(bessie_data) != M:
        print("Error: invalid data")
        exit(1)

    limits = list(itertools.chain(*[[limit] * length for length, limit in limit_data]))
    bessie = list(itertools.chain(*[[speed] * length for length, speed in bessie_data]))

    if len(limits) != 100 or len(bessie) != 100:
        print("Error: invalid data")
        exit(1)

maximum_infraction = 0
for i in range(100):
    infraction = bessie[i] - limits[i]
    maximum_infraction = max(maximum_infraction, infraction)

with open("speeding.out", "w") as fout:
    fout.write("{}\n".format(maximum_infraction))
