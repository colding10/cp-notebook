N = int(input())

case = ['0', '1']

for i in range(N - 1):
    new_case = ['0' + i for i in case]
    new_case2 = ['1' + i for i in case[::-1]]
    
    case = new_case + new_case2

print('\n'.join(case))