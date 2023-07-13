x = 0
y = 0


def x_value(chr, count):
    if chr not in "<>":
        return 0
    m = {"<": -2, ">": 2}
    if count < 3:
        return m[chr] * count
    return m[chr] / 2 * 20 + (m[chr] / 2 * 5 * (count - 3))


def y_value(chr, count):
    if chr not in "v^":
        return 0
    m = {"v": -2, "^": 2}
    if count < 3:
        return m[chr] * count
    return m[chr] / 2 * 20 + (m[chr] / 2 * 5 * (count - 3))


s = input()

tokens = ["g"]
char_adding = ""
for i, c in enumerate(s):
    if tokens[-1][0] != c:
        tokens.append([c, 1])
    else:
        tokens[-1][1] += 1

del tokens[0]
for chr, count in tokens:
    x += int(x_value(chr, count))
    y += int(y_value(chr, count))

print(f"({x},{y})")
