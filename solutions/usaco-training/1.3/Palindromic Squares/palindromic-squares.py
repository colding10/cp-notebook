'''
ID: colindi1
LANG: PYTHON3
TASK: palsquare
'''

# simple math again

def numberToBase(n, b):
        if n == 0:
            return [0]
        digits = []
        while n:
            digits.append(int(n % b))
            n //= b
        digits = digits[::-1]
        for index in range(len(digits)):
            digit = digits[index]
            if len(str(digit)) > 1:
                digits[index] = over_flow_digits[digit]
        return (''.join([str(x) for x in digits]))

with open('palsquare.in', 'r') as file:
    B = int(file.readline().replace('\n', ''))
    
over_flow_digits = {10:'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F', 16:'G', 17:'H', 18:'I', 19:'J'}

out = ''
for N in range(1, 301):
    n_squared = N * N
    
    n_squared_based = numberToBase(n_squared, B)
    if str(n_squared_based) == str(n_squared_based)[::-1]:
        out += f'{numberToBase(N, B)} {n_squared_based}'
        out += '\n'

with open('palsquare.out', 'w') as file:
    file.write(out)
