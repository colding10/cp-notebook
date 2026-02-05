'''
ID: colindi1
LANG: PYTHON3
TASK: sort3
'''

# find number of swaps that correct 2 values
# by counting 1s in a 3 spot, 2s in a 3 spot, 1s in a 2 spot, and vice versa
# one swap can correct both these values

# the remaining misplaced elements form cycles: 
# a 1 where a 2 should be, a 2 where a 3 should be, and 3 where the 1 should be. 
# it takes two swaps to correct such a cycle. 
# so we count the number of such cycles (by counting misplaced elements and dividing by three)
# and then add in two times that many swaps.

# line 38 calculates the amount of swaps that correct 2 values
# line 39 calculates the remaining "cycles" and add 2 times that 

with open('sort3.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

number_of_lines = int(lines.pop(0))

numbers_list = list(map(int, lines))
correct_numbers_list = sorted(numbers_list)

number_of_swaps = 0
misplaced = 0

misplaced_in = {(1, 3): 0, (2, 3): 0, (1, 2): 0, (3, 1): 0, (3, 2): 0, (2, 1): 0}
for index, value in enumerate(numbers_list):
    correct_value = correct_numbers_list[index]
    if value != correct_value:
        misplaced_in[(value, correct_value)] += 1



out = min(misplaced_in[(1, 2)], misplaced_in[(2, 1)]) + min(misplaced_in[(1, 3)], misplaced_in[(3, 1)]) + min(misplaced_in[(2, 3)], misplaced_in[(3, 2)]) 
out += (2 * (max(misplaced_in[(1, 2)], misplaced_in[(2, 1)]) - min(misplaced_in[(1, 2)], misplaced_in[(2, 1)])))

out = str(out)

with open('sort3.out', 'w') as file:
    file.write(out + '\n')