'''
ID: colindi1
LANG: PYTHON3
TASK: namenum
'''

import itertools

# go through possible names
# PRUNE BY NAME LENGTH

letter_to_numbers = {2 : ('A','B','C'), 3: ("D","E","F"), 4: ("G","H","I"), 5: ("J","K","L"), 6: ("M","N","O"), 7: ("P","R","S") , 8: ("T","U","V"), 9:("W","X","Y")}

def getAllPossible(serial):
    digits = [int(i) for i in list(str(serial))]
    possibles = []
    for digit in digits:
        possible_letters = letter_to_numbers[digit]
        possibles.append(possible_letters)
    cases = (itertools.product(*possibles))
    return [''.join(i) for i in cases]

with open('namenum.in', 'r') as file:
    serial = int(file.readline().replace('\n', ''))

with open('dict.txt', 'r') as file:
    valid_names = [i for i in [line.replace('\n', '') for line in file.readlines()] if len(i) == len(str(serial))]
    #valid_names = [line.replace('\n', '') for line in file.readlines()]

good_names = []

for name in valid_names:
    if name in getAllPossible(serial):
        good_names.append(name)

if not good_names:
    out = 'NONE\n'
else:
    out = '\n'.join(good_names) + '\n'

with open('namenum.out', 'w') as file:
    file.write(out)
