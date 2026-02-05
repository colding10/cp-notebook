'''
ID: colindi1
LANG: PYTHON3
TASK: frac1
'''

# just generate possible fractions (add 1/1) and check if value is not already there


with open('frac1.in', 'r') as file:
    N = int(file.readline().strip())

fractions = ['1/1']
values = [1]

for denom in range(1, N+1):
    for numerator in range(denom):
        value = numerator/denom
        fraction = f'{numerator}/{denom}'
        if value not in values:
            values.append(value)
            fractions.append(fraction)

fractions.sort(key=lambda d: eval(d))

out = '\n'.join(fractions)

with open('frac1.out', 'w') as file:
    file.write(out + '\n')
