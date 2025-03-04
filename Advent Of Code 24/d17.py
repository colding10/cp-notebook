def load_program(filename):
    with open(filename, 'r') as file:
        data = file.read().strip()
    
    lines = data.split('\n')
    registers = {}
    program = []

    for line in lines:
        if line.startswith("Register"):
            parts = line.split(":")
            registers[parts[0].split()[-1]] = int(parts[1].strip())
        elif line.startswith("Program"):
            program = list(map(int, line.split(":")[1].strip().split(",")))
    
    return registers, program

def run_program(registers, program):
    def get_combo_value(operand):
        if operand <= 3:
            return operand
        elif operand == 4:
            return registers['A']
        elif operand == 5:
            return registers['B']
        elif operand == 6:
            return registers['C']
        raise ValueError("Invalid combo operand")
    
    instruction_pointer = 0
    output = []

    while instruction_pointer < len(program):
        opcode = program[instruction_pointer]
        operand = program[instruction_pointer + 1]
        instruction_pointer += 2  # Default increment

        if opcode == 0:  # adv
            denom = 2 ** get_combo_value(operand)
            registers['A'] //= denom
        elif opcode == 1:  # bxl
            registers['B'] ^= operand
        elif opcode == 2:  # bst
            registers['B'] = get_combo_value(operand) % 8
        elif opcode == 3:  # jnz
            if registers['A'] != 0:
                instruction_pointer = operand
        elif opcode == 4:  # bxc
            registers['B'] ^= registers['C']
        elif opcode == 5:  # out
            output.append(get_combo_value(operand) % 8)
        elif opcode == 6:  # bdv
            denom = 2 ** get_combo_value(operand)
            registers['B'] = registers['A'] // denom
        elif opcode == 7:  # cdv
            denom = 2 ** get_combo_value(operand)
            registers['C'] = registers['A'] // denom
        else:
            raise ValueError("Invalid opcode")
    
    return output

def find_minimum_a(program):
    a_value = 1  # Start from 1 (smallest positive integer)
    while True:
        registers = {'A': a_value, 'B': 0, 'C': 0}
        output = run_program(registers, program)
        if output == program:  # Check if output matches the program
            return a_value
        a_value += 1

def main():
    registers, program = load_program("input.txt")
    
    # Part 1
    part1_registers = registers.copy()
    part1_output = run_program(part1_registers, program)
    print("Part 1 Output:", ",".join(map(str, part1_output)))

    # Part 2
    part2_solution = find_minimum_a(program)
    print("Part 2 Solution:", part2_solution)

if __name__ == "__main__":
    main()