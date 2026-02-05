'''
ID: colindi1
LANG: PYTHON3
TASK: barn1
'''

# greedy algorithm, build up solutions
# by removing a section that saves the most wood every time
# until the optimal solution is reached

with open('barn1.in', 'r') as file:
    #lines = ['4 50 17', '3', '4', '6', '8', '14', '15', '16', '17', '21', '25', '26', '27', '30', '31', '40', '41', '42', '43']
    lines = [line.replace('\n', '') for line in file.readlines()]

maximum_boards, total_stalls, cows_in_stalls = list(map(int, lines.pop(0).split(' ')))
#print(maximum_boards, total_stalls, cows_in_stalls)
occupied_stalls = []

for line in lines:
    occupied_stalls.append(int(line))

occupied_stalls.sort()

blocked_dict = {index: [False, (index in occupied_stalls)] for index in range(min(occupied_stalls), max(occupied_stalls) + 1)}

covered_stalls = 0
M = 1
while True:
    #print(M)
    
    if M == 1:
        for key in blocked_dict.keys():
            blocked_dict[key] = [True, blocked_dict[key][1]]
            covered_stalls += 1
        M += 1
        continue

    if covered_stalls == cows_in_stalls or M > maximum_boards:
        break
    
    unoccupied_covered_stalls = dict()
    not_occupied_streak = 0
    starting_index = 0
    ending_index = 0

    for key in blocked_dict.keys():
        value = blocked_dict[key]
        covered, occupied = value

        if not covered:
            continue
        
        if occupied:
            if not_occupied_streak == 0:
                starting_index = list(blocked_dict.keys()).index(key) + min(list(blocked_dict.keys()))
            ending_index = list(blocked_dict.keys()).index(key) + min(list(blocked_dict.keys()))

            if not_occupied_streak != 0:
                unoccupied_covered_stalls[(starting_index, ending_index)] = not_occupied_streak
                not_occupied_streak = 0

        else:
            if not_occupied_streak == 0:
                starting_index = list(blocked_dict.keys()).index(key) + min(list(blocked_dict.keys()))
            not_occupied_streak += 1

    #print(unoccupied_covered_stalls)
    max_streak = max(unoccupied_covered_stalls.values())
    starting_max_index, ending_max_index = list(unoccupied_covered_stalls.keys())[list(unoccupied_covered_stalls.values()).index(max_streak)]

    for index in range(starting_max_index, ending_max_index):
        blocked_dict[index] = (False, blocked_dict[index][1])
        covered_stalls -= 1
    M += 1
    
with open('barn1.out', 'w') as file:
    file.write(str(covered_stalls) + '\n')