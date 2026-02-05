'''
ID: colindi1
LANG: PYTHON3
TASK: holstein
'''

# calculate all possible scoops (can only be 1 or 0 scoops per feed type)
# so we find that, and then filter to get only the ones that fufill the vitamin requirement
# and then find the one that required least scoops (get the minimum if scoops is same, finds smallest feedtype numbers)

from itertools import combinations

def calculateVitaminsRecieved(feed_combination):
    recieved = []

    for index in range(number_of_vitamin_types):
        total = 0
        for scoop in feed_combination:
            total += scoop[index]
        recieved.append(total)
    
    return recieved

def isEnoughVitamins(recieved, required):
    for index in range(number_of_vitamin_types):
        recieved_vitamin_amount = recieved[index]
        required_vitamin_amount = required[index]

        if recieved_vitamin_amount < required_vitamin_amount:
            return False
    
    return True


with open('holstein.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

number_of_vitamin_types = int(lines.pop(0))
vitamin_requirements_per_cow = list(map(int, lines.pop(0).strip().split()))

number_of_types_of_feeds = int(lines.pop(0))
feeds_info = []

for line in lines:
    feeds_info.append(list(map(int, line.strip().split())))

possible_feeds_combinations = []

for amount_to_choose in range(1, number_of_vitamin_types + 1):
    possible_amount = list(combinations(feeds_info, amount_to_choose))
    for combi in possible_amount:
        possible_feeds_combinations.append(combi)


working_feeds_combinations = [feed_combination for feed_combination in possible_feeds_combinations if isEnoughVitamins(calculateVitaminsRecieved(feed_combination), vitamin_requirements_per_cow)]

working_feeds_lengths = [len(item) for item in working_feeds_combinations]

minimum_scoops_of_feed = min(working_feeds_lengths)

working_smallest_scoops_combinations = [feed_combination for feed_combination in working_feeds_combinations if len(feed_combination) == minimum_scoops_of_feed]

best_case = min(working_smallest_scoops_combinations)

best_case_indexes = [str(feeds_info.index(scoop) + 1) for scoop in best_case]

out = str(minimum_scoops_of_feed) + ' ' + ' '.join(best_case_indexes) + '\n'

with open('holstein.out', 'w') as file:
    file.write(out)