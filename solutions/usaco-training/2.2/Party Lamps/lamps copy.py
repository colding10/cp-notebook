'''
ID: colindi1
LANG: PYTHON3
TASK: lamps
'''

from copy import deepcopy
from itertools import combinations_with_replacement

with open('lamps.in', 'r') as file:
    N = int(file.readline().strip())
    C = int(file.readline().strip())

    on_lamps = list(map(int, file.readline().strip().split(' ')))
    off_lamps = list(map(int, file.readline().strip().split(' ')))

    on_lamps.remove(-1)
    off_lamps.remove(-1)

def button1(state):
    state_copy = state
    to_change = dict()

    for index, lamp in enumerate(state_copy):
        if lamp:
            to_change[index] = 0
        else:
            to_change[index] = 1
    
    for item in to_change.items():
        state_copy[item[0]] = item[1]
    
    return state_copy

def button2(state):
    state_copy = state
    to_change = dict()

    for index, lamp in enumerate(state_copy):
        if not index % 2:
            if lamp:
                to_change[index] = 0
            else:
                to_change[index] = 1
        
    for item in to_change.items():
        state_copy[item[0]] = item[1]
    
    return state_copy

def button3(state):
    state_copy = state
    to_change = dict()

    for index, lamp in enumerate(state_copy):
        if index % 2:
            if lamp:
                to_change[index] = 0
            else:
                to_change[index] = 1
        
    for item in to_change.items():
        state_copy[item[0]] = item[1]
    
    return state_copy

def button4(state):
    state_copy = state
    to_change = dict()

    for index, lamp in enumerate(state_copy):
        if not index % 3:
            if lamp:
                to_change[index] = 0
            else:
                to_change[index] = 1
        
    for item in to_change.items():
        state_copy[item[0]] = item[1]
    
    return state_copy

possible_operations = [button1, button2, button3, button4]

all_possible_operations = combinations_with_replacement(possible_operations, C)
all_possible_states = []

for operation_sequence in all_possible_operations:
    state = [1 for _ in range(N)]

    for operation in operation_sequence:
        state = operation(state)
    
    should_be_on_lamps = [state[lamp_number-1] for lamp_number in on_lamps]
    should_be_off_lamps = [state[lamp_number-1] for lamp_number in off_lamps]

    if any(should_be_off_lamps) or not all(should_be_on_lamps):
        continue
    
    to_append = ''.join(map(str, state))

    if to_append not in all_possible_states:
        all_possible_states.append(to_append)

if not all_possible_states:
    all_possible_states.append('IMPOSSIBLE')

all_possible_states.sort()

with open('lamps.out', 'w') as file:
    file.write('\n'.join(all_possible_states) + '\n')