'''
ID: colindi1
LANG: PYTHON3
TASK: dualpal
'''

# simple math

with open('dualpal.in', 'r') as file:
    N, S = [int(i) for i in ((file.readline().replace('\n', '')).split(' '))]

def numberToBase(n, b):
        """ Converts number n to base b """
        if n == 0:
            return [0]
        digits = []
        while n:
            digits.append(int(n % b))
            n //= b
        digits = digits[::-1]
        return int(''.join([str(x) for x in digits]))
    
count = 0
bases = list(range(2, 11))

out = ''
for x in range(S+1, 10000**2):
    good = 0
    for base in bases:
        converted = numberToBase(x, base)
        if str(converted) == str(converted)[::-1]:
            good += 1
        if good > 1:
            break
    if good > 1:
        count += 1
        out += str(x)
        out += '\n'
        if count >= N:
            break

with open('dualpal.out', 'w') as file:
    file.write(out)
