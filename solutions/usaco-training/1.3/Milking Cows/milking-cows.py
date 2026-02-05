'''
ID: colindi1
LANG: PYTHON3
TASK: milk2
'''

# work through times

def sortKey(line):
	if line:
		start, end = map(int, line.strip().split(' '))
		return start

with open('milk2.in','r') as file:
	number_of_cows = int(file.readline().strip())
	times = file.read().split('\n')

times = list(filter(None, times))
times.sort(key = sortKey)
minimum_start, minimum_start_end = map(int, times[0].strip().split(' '))

longest_continuous_milking = minimum_start_end - minimum_start
longest_idle_time = 0

for time in times:
	if time:
		start, end = map(int, time.strip().split(' '))

		if start - minimum_start_end >= longest_idle_time :
			longest_idle_time = start - minimum_start_end

		if minimum_start <= start and start <= minimum_start_end:
			if minimum_start_end < end:
				minimum_start_end = end
		else:
			if minimum_start_end - minimum_start > longest_continuous_milking:
				longest_continuous_milking = minimum_start_end - minimum_start
			minimum_start, minimum_start_end = start, end

with open('milk2.out','w') as file:
	file.write(f"{longest_continuous_milking} {longest_idle_time}\n")