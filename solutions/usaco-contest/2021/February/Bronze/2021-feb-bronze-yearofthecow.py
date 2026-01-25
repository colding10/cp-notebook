from sys import stdin, stdout


def calculate_delta(relative, z1, z2):
    x1 = cycle.index(z1)

    change = 0
    if relative == "next":
        while cycle[x1] != z2:
            change += 1
            x1 = x1 + 1 if x1 < 11 else 0

    else:
        while cycle[x1] != z2:
            change -= 1
            x1 = x1 - 1 if x1 > 0 else 11

    return change


cycle = [
    "Ox",
    "Tiger",
    "Rabbit",
    "Dragon",
    "Snake",
    "Horse",
    "Goat",
    "Monkey",
    "Rooster",
    "Dog",
    "Pig",
    "Rat",
]


lines = int(stdin.readline())

birth_years = {"Bessie": 0}
birth_zodiacs = {"Bessie": "Ox"}

for _ in range(lines):
    words = stdin.readline().strip().split()
    name1 = words[0]
    name2 = words[7]
    relative = words[3]
    year_name = words[4]

    if name2 not in birth_years:
        birth_years[name2] = 0

    difference = calculate_delta(relative, birth_zodiacs[name2], year_name)

    birth_years[name1] = birth_years[name2] - difference
    birth_zodiacs[name1] = year_name

print(birth_years["Bessie"] - birth_years["Elsie"])
