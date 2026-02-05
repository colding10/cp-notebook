'''
ID: colindi1
LANG: PYTHON3
TASK: ariprog
'''

# did not pass time check, used Java

import time
from itertools import combinations_with_replacement

with open('ariprog.in', 'r') as file:
    N, M = map(int, [line.replace('\n', '') for line in file.readlines()])
    
def calculateBisquares(limit):
    p_or_q_values = range(limit+1)
    return sorted(set([((i[0]**2) + (i[1]**2)) for i in combinations_with_replacement(p_or_q_values, 2)]))

def checkNum(bisquare_index, all_bisquares, difference):
    for sequence_item_number in range(2, N):
        if(all_bisquares[bisquare_index] + difference * sequence_item_number) not in all_bisquares:
            return False
    return True


print(f'starting: {time.time()}')
start = time.time()

all_bisquares = calculateBisquares(M)
maximum_number = 2 * (M ** 2)
sequences = []

for starting_index in range(0, len(all_bisquares) - N + 1):
    for ending_index in range(starting_index + 1, len(all_bisquares) - N + 2):
        difference = all_bisquares[ending_index] - all_bisquares[starting_index]

        if all_bisquares[starting_index] + (N - 1) * difference > maximum_number:
            break
        if checkNum(starting_index, all_bisquares, difference):
            sequences.append([all_bisquares[starting_index], difference])


if len(sequences) != 0:
    sequences.sort(key=lambda d: d[1])

    out = '\n'.join([' '.join(map(str, sequence)) for sequence in sequences])
else:
    out = 'NONE'

print(f'ending: {time.time()}')
print(f'time taken: {time.time()-start}')


with open('ariprog.out', 'w') as file:
    file.write(out + '\n')

