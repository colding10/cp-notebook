'''
ID: colindi1
LANG: PYTHON3
TASK: combo
'''

# brute force, get all possible combinations

def get_before(a_list, index):
    try:
        return a_list[index-1]
    except:
        return a_list[-1]
    
def get_after(a_list, index):
    try:
        return a_list[index + 1]
    except:
        return a_list[0]

with open('combo.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

N = int(lines.pop(0))

combos_list = list(range(1, N+1))
all_possible_combinations = []

john_combination = list(map(int, lines.pop(0).split(' ')))
master_combination = list(map(int, lines.pop(0).split(' ')))

possible_digit_one_john = []
possible_digit_two_john = []
possible_digit_three_john = []
index = 0

for digit in john_combination:
    digit_combos_index = combos_list.index(digit)
    digit_index = index
    index += 1
    number = digit_index + 1
    number_to_letter_number = {1:'one',2:'two',3:'three'}

    within_two_digits = [get_before(combos_list, (digit_combos_index - 1)%N), get_before(combos_list, digit_combos_index%N), digit, get_after(combos_list, digit_combos_index%N), get_after(combos_list, (digit_combos_index + 1)%N)]
    for within_two_digit in within_two_digits:
        exec(f'possible_digit_{number_to_letter_number[number]}_john.append({within_two_digit})', globals(), locals())

for d1 in possible_digit_one_john:
    for d2 in possible_digit_two_john:
        for d3 in possible_digit_three_john:
            all_possible_combinations.append((d1, d2, d3))
            
if master_combination != john_combination:
    possible_digit_one_master = []
    possible_digit_two_master = []
    possible_digit_three_master = []
    index = 0
    for digit in master_combination:
        digit_combos_index = combos_list.index(digit)
        digit_index = index
        index += 1
        number = digit_index + 1
        number_to_letter_number = {1:'one',2:'two',3:'three'}

        within_two_digits = [get_before(combos_list, (digit_combos_index - 1)%N), get_before(combos_list, digit_combos_index%N), digit, get_after(combos_list, digit_combos_index%N), get_after(combos_list, (digit_combos_index + 1)%N)]
        for within_two_digit in within_two_digits:
            exec(f'possible_digit_{number_to_letter_number[number]}_master.append({within_two_digit})', globals(), locals())

    for d1 in possible_digit_one_master:
        for d2 in possible_digit_two_master:
            for d3 in possible_digit_three_master:
                all_possible_combinations.append((d1, d2, d3))
                
all_possible_combinations.append(tuple(master_combination))
all_possible_combinations.append(tuple(john_combination))

all_possible_combinations = list(set(all_possible_combinations))


with open('combo.out', 'w') as file:
    file.write(str(len(all_possible_combinations)) + '\n')