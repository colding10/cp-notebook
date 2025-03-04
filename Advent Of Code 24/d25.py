def parse_schematic(lines):
    """
    Convert schematics into heights per column.
    Locks: Measure pin heights from the top.
    Keys: Measure key heights from the bottom.
    """
    num_columns = len(lines[0])
    heights = [0] * num_columns

    for col in range(num_columns):
        for row in range(len(lines)):
            if lines[row][col] == '#':
                heights[col] += 1
    return heights


def fits_together(lock, key, max_height):
    """
    Check if a lock and key fit without overlapping.
    """
    for l, k in zip(lock, key):
        if l + k > max_height:
            return False
    return True


def main():
    with open("input.txt") as file:
        data = file.read().strip().split("\n\n")
    
    locks = []
    keys = []

    # Parse input into locks and keys
    for schematic in data:
        lines = schematic.splitlines()
        if lines[0] == "#" * len(lines[0]):  # Lock: Top row filled
            locks.append(parse_schematic(lines))
        elif lines[-1] == "#" * len(lines[0]):  # Key: Bottom row filled
            keys.append(parse_schematic(lines[::-1]))  # Reverse for key heights

    max_height = len(data[0].splitlines())  # Maximum pin/key height

    # Count valid lock/key pairs
    count = 0
    for lock in locks:
        for key in keys:
            if fits_together(lock, key, max_height):
                count += 1

    print(count)


if __name__ == "__main__":
    main()