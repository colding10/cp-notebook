
'''
ID: colindi1
LANG: PYTHON3
TASK: friday
'''

# iterate through months and check for leap years too

with open('friday.in', 'r') as file:
    N = int(file.readline())

days_of_weeks = {i : 0 for i in range(7)}
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day = 0
for year in range(1900, 1900 + N):
	for month in months:
		days_of_weeks[day % 7] += 1
		if(month == 28):
			if(year % 400 == 0 or (year % 100 != 0 and year % 4 == 0)):
				day += 29
				continue
		day += month

with open('friday.out','w') as file:
	for day in range(6):
		file.write(f'{days_of_weeks[day]} ')
	file.write(f"{days_of_weeks[6]}\n")