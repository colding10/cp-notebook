'''
ID: colindi1
LANG: PYTHON3
TASK: milk2
'''

stdin = open('milk2.in', 'r')
stdout = open('milk2.out', 'w')

# work through times
class Event:
    def __init__(self, starting, ending):
        self.starting = starting
        self.ending = ending
    
    def __repr__(self):
        return f'<Event> (starting={self.starting}, ending={self.ending})'


number_of_cows = int(stdin.readline().strip())

times = [list(map(int, item.split())) for item in stdin.read().split('\n') if item]
times.sort(key = lambda d: (d[0], d[1]))

events = [Event(*time) for time in times]
maximum_not_milking = float('inf') * -1
maximum_milking = float('inf') * -1

previous_event = events[0]
for event in events[1:]:
    if event.starting <= previous_event.ending: # merge two events
        previous_event.ending = max(event.ending, previous_event.ending)
        events.remove(event)
    else:
        previous_event = event

previous_event = Event(0, events[0].starting)
for event in events:
    milking_time = event.ending - event.starting
    not_milking_time = event.starting - previous_event.ending
    
    maximum_milking = max(maximum_milking, milking_time)
    maximum_not_milking = max(maximum_not_milking, not_milking_time)
    
    previous_event = event

stdout.write(f'{maximum_milking} {maximum_not_milking}\n')
