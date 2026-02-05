'''
ID: colindi1
LANG: PYTHON3
TASK: milk3
'''

# go through all possible pouring cases
# find cases where bucket a is empty
# only go through new cases

with open('milk3.in', 'r') as file:
    A, B, C = map(int, file.readline().strip().split())

capacities = [A, B, C]
starting_milk_volumes = [0, 0, C]

result = set()
final_milk_cases = []

def solve(starting_milk_volumes):
    for index1, milk_amount_1 in enumerate(starting_milk_volumes):
        for index2, milk_amount_2 in enumerate(starting_milk_volumes):
            if index1 != index2:
                milk_amounts_case = list(starting_milk_volumes)
                if capacities[index2] - milk_amount_2 >= milk_amount_1:
                    milk_amounts_case[index2] = milk_amount_2 + milk_amount_1
                    milk_amounts_case[index1] = 0
                else:
                    milk_amounts_case[index1] = milk_amount_1 - (capacities[index2] - milk_amount_2)
                    milk_amounts_case[index2] = capacities[index2]
                if not milk_amounts_case[-1] in result and milk_amounts_case not in final_milk_cases:
                    if milk_amounts_case[0] == 0:
                        result.add(milk_amounts_case[-1])
                    final_milk_cases.append(milk_amounts_case)
                    solve(milk_amounts_case)

solve(starting_milk_volumes)                
result = sorted(list(result))

out = ' '.join(map(str, result))

with open('milk3.out', 'w') as file:
    file.write(out + '\n')