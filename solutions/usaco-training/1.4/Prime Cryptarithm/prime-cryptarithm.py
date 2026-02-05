'''
ID: colindi1
LANG: PYTHON3
TASK: crypt1
'''

# brute force again, just generate all cases and then test the cases

def generateAllCases(digits):
    cases = []
    possible_number_one = []
    possible_number_two = []

    for digit1 in digits:
        for digit2 in digits:
            number = f'{digit1}{digit2}'
            possible_number_two.append(int(number))
            for digit3 in digits:
                number = f'{digit1}{digit2}{digit3}'
                possible_number_one.append(int(number))
    
    for number1 in list(set(possible_number_one)):
        for number2 in list(set(possible_number_two)):
            cases.append((number1, number2))
    
    return list(set(cases))

def testCase(number1, number2):
    partial_one = int(str(number2)[1]) * number1
    partial_two = int(str(number2)[0]) * number1
    result = number1 * number2

    if len(str(partial_one)) > 3 or len(str(partial_two)) > 3 or len(str(result)) > 5:
        return False
    
    for digit in list(map(int, list(str(partial_one)))):
        if digit not in digits:
            return False
    
    for digit in list(map(int, list(str(partial_two)))):
        if digit not in digits:
            return False
    
    for digit in list(map(int, list(str(result)))):
        if digit not in digits:
            return False
    
    return True

with open('crypt1.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

number_of_digits = int(lines.pop(0))

digits = list(map(int, lines.pop(0).split(' ')))

working_cases = 0

cases = list(set(generateAllCases(digits)))

for case in cases:
    if testCase(*case):
        working_cases += 1

with open('crypt1.out', 'w') as file:
    file.write(str(working_cases) + '\n')