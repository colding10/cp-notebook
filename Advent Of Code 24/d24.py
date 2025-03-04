import itertools

def parse_input(input_data):
    """Parses the input into initial values and gates."""
    initial_values = {}
    gates = []

    for line in input_data.strip().split("\n"):
        if "->" in line:
            # Parse gate
            parts = line.split(" -> ")
            out = parts[1].strip()
            operation = parts[0].split()
            
            if len(operation) == 1:
                # Direct assignment (e.g., 123 -> x)
                a = operation[0]
                op = None
                b = None
            elif len(operation) == 2:
                # NOT gate (e.g., NOT x -> y)
                op = "NOT"
                a = operation[1]
                b = None
            else:
                # Binary gate (e.g., x AND y -> z)
                a = operation[0]
                op = operation[1]
                b = operation[2]

            gates.append((a, op, b, out))
        else:
            # Parse initial value
            wire, value = line.split(": ")
            initial_values[wire.strip()] = int(value)

    return initial_values, gates


def simulate_circuit(initial_values, gates):
    """Simulates the circuit and returns the final values of all wires."""
    values = initial_values.copy()

    while True:
        resolved = False
        for a, op, b, out in gates:
            if out in values:
                continue  # Skip if output wire already has a value
            
            try:
                # Resolve inputs
                val_a = int(a) if a.isdigit() else values[a]
                val_b = int(b) if b and b.isdigit() else (values[b] if b else None)

                # Perform operation
                if op is None:
                    values[out] = val_a
                elif op == "AND":
                    values[out] = val_a & val_b
                elif op == "OR":
                    values[out] = val_a | val_b
                elif op == "LSHIFT":
                    values[out] = val_a << val_b
                elif op == "RSHIFT":
                    values[out] = val_a >> val_b
                elif op == "NOT":
                    values[out] = ~val_a & 0xFFFF  # Ensure 16-bit result

                resolved = True
            except KeyError:
                # Inputs not yet resolved; skip this gate for now
                continue

        if not resolved:
            break

    return values


def find_swaps(initial_values, gates):
    """Finds the wires that need to be swapped to fix the circuit."""
    n_bits = len([wire for wire in initial_values if wire.startswith("x")])
    x_val = int("".join(str(initial_values[f"x{i:02}"]) for i in range(n_bits)[::-1]), 2)
    y_val = int("".join(str(initial_values[f"y{i:02}"]) for i in range(n_bits)[::-1]), 2)
    expected_z = bin(x_val + y_val)[2:].zfill(n_bits + 1)

    # Simulate circuit without swaps
    values = simulate_circuit(initial_values, gates)
    actual_z = "".join(str(values[f"z{i:02}"]) for i in range(len(expected_z))[::-1])

    # Find mismatched wires
    mismatch_wires = []
    for i, (expected, actual) in enumerate(zip(expected_z, actual_z)):
        if expected != actual:
            mismatch_wires.append(f"z{i:02}")

    # Identify pairs of swaps
    for swap_combination in itertools.combinations(mismatch_wires, 8):  # 8 wires = 4 pairs
        swapped_gates = gates[:]
        swap_map = {swap_combination[i]: swap_combination[i + 1] for i in range(0, len(swap_combination), 2)}
        swap_map.update({v: k for k, v in swap_map.items()})  # Reverse mapping for bi-directional swaps

        # Apply swaps to the gates
        swapped_gates = [
            (a, op, b, swap_map.get(out, out)) for a, op, b, out in swapped_gates
        ]

        # Simulate the swapped circuit
        values = simulate_circuit(initial_values, swapped_gates)
        actual_z = "".join(str(values[f"z{i:02}"]) for i in range(len(expected_z))[::-1])

        if actual_z == expected_z:
            return sorted(swap_combination)

    return None  # If no solution is found


if __name__ == "__main__":
    # Replace with actual puzzle input
    puzzle_input = """<your input here>"""

    initial_values, gates = parse_input(puzzle_input)
    swapped_wires = find_swaps(initial_values, gates)

    if swapped_wires:
        print(",".join(swapped_wires))
    else:
        print("No solution found.")