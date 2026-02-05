'''
ID: colindi1
LANG: PYTHON3
TASK: zerosum
'''


input = open('zerosum.in', 'r').readline
print = lambda t: open('zerosum.out', 'w').write(t + '\n')
 
N = int(input())

cases = []

def solve(i, exp):
    if i > N:
        cases.append(exp)
    else:
        solve(i + 1, f'{exp}+{i}')
        solve(i + 1, f'{exp}-{i}')
        solve(i + 1, f'{exp} {i}')

solve(2, '1')

outlines = []

for case in cases:
    if eval(case.replace(' ', '')) == 0:
        outlines.append(case)

print('\n'.join(sorted(outlines)))