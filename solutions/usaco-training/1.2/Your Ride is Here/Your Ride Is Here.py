'''
ID: colindi1
LANG: PYTHON3
TASK: ride
'''

# simple addition and mods

def getNumberProduct(letter_string):
    return eval('*'.join([str(i) for i in [ord(letter) - 64 for letter in letter_string]]))

with open('ride.in', 'r') as file:
    lines = [i.replace('\n', '') for i in file.readlines()]

    first = lines[0]
    second = lines[1]

if getNumberProduct(first) % 47 == getNumberProduct(second) % 47:
    with open('ride.out', 'w') as file:
        file.write('GO\n')
else:
    with open('ride.out', 'w') as file:
        file.write('STAY\n')