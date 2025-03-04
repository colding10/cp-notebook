with open("input.txt", "r", encoding="utf8") as file:
    data = file.read().splitlines()


def dp(sequence, layers):
    key_layouts = [
        {
            ch: (x, y)
            for y, row in enumerate([" ^A", "<v>"])
            for x, ch in enumerate(row)
        },
        {
            ch: (x, y)
            for y, row in enumerate(["789", "456", "123", " 0A"])
            for x, ch in enumerate(row)
        },
    ]

    trans = {
        (0, start, end): 1 for start in key_layouts[0] for end in key_layouts[0]
    }

    def calc_path(layer, path):
        return sum(trans[(layer, src, dst)] for src, dst in zip("A" + path, path))

    for layer in range(1, layers + 1):
        curr_key = key_layouts[1] if layer == layers else key_layouts[0]
        for start, (x1, y1) in curr_key.items():
            for end, (x2, y2) in curr_key.items():
                hor_steps = (">" if x2 > x1 else "<") * abs(x2 - x1)
                ver_steps = ("^" if y2 < y1 else "v") * abs(y2 - y1)

                horiz_first = (
                    calc_path(layer - 1, hor_steps + ver_steps + "A")
                    if (x2, y1) != curr_key.get(" ", (None, None))
                    else float("inf")
                )
                vert_first = (
                    calc_path(layer - 1, ver_steps + hor_steps + "A")
                    if (x1, y2) != curr_key.get(" ", (None, None))
                    else float("inf")
                )
                trans[(layer, start, end)] = min(horiz_first, vert_first)

    return calc_path(layers, sequence)


# Calculate results for both parts
p1 = sum(dp(seq, 3) * int(seq[:-1]) for seq in data)
p2 = sum(dp(seq, 26) * int(seq[:-1]) for seq in data)

print(p1, p2)
