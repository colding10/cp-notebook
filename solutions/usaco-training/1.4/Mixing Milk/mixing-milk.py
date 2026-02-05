'''
ID: colindi1
LANG: PYTHON3
TASK: milk
'''

# simple logic, buy as much as possible (or needed) from the cheapest farmer
# and then go to the next cheapest farmer after cheapest stock exhausted

with open('milk.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

price = 0

wanted_units, farmers_available = map(int, lines.pop(0).split(' '))
units_to_buy = wanted_units

farmer_info = []
for _ in range(farmers_available):
    farmer_info.append(list(map(int, lines.pop(0).split(' '))))

farmer_info = sorted(farmer_info, key=lambda i:i[0])
#print(farmer_info)
for price_per_unit, available_units in farmer_info:
    if units_to_buy == 0:
        break

    if available_units >= units_to_buy:
        buy_amount = units_to_buy

    else:
        if available_units <= units_to_buy:
            buy_amount = available_units
        else:
            buy_amount = units_to_buy
    
    money_to_spend = buy_amount * price_per_unit
    #print(buy_amount, price_per_unit, available_units, units_to_buy)
    price += money_to_spend
    units_to_buy -= buy_amount

with open('milk.out', 'w') as file:
    file.write(f'{price}\n')