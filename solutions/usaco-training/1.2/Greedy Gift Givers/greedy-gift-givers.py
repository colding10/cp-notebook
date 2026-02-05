'''
ID: colindi1
LANG: PYTHON3
TASK: gift1
'''


# create variables for each person and add

with open('gift1.in', 'r') as file:
    lines = [i.replace('\n', '') for i in file.readlines()]

number_of_people = int(lines.pop(0))

people = []

for x in range(number_of_people):
    people.append(lines.pop(0))

for person in people:
    exec(f'{person} = 0')

for x in range(number_of_people):
    giver_person = lines.pop(0)
    give_amount = lines.pop(0)
    #print(give_amount)

    try:
        give_amount, give_people_number = [int(i) for i in give_amount.split(' ')]
    except ValueError:
        continue
    
    if give_people_number == 0 or give_amount == 0:
        continue

    give_amount_per_person, to_keep = divmod(give_amount, give_people_number)

    people_to_give = []
    for y in range(give_people_number):
        people_to_give.append(lines.pop(0))
    
    for person in people_to_give:
        exec(f'{person} += {give_amount_per_person}')

    exec(f'{giver_person} -= {give_amount}')
    exec(f'{giver_person} += {to_keep}')

out = ''
for person in people:
    out += ((person + ' ' + str(eval(person))) + '\n')

with open('gift1.out', 'w') as file:
    file.write(out)