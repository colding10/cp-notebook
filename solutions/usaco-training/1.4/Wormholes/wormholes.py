'''
ID: colindi1
LANG: PYTHON3
TASK: wormhole
'''

# somewhat complex, create a Coord object for the wormholes
# with methods such as the x, y, and what it is paired to
# using this class, we can easily go through the wormholes
# using an array to save our route
# to see if we are trapped in a loop
class Coord(object):
    """Instances of the wormhole instances"""

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.paired = None

    def next(self):
        """
        Returns: the next wormhole the cow will encounter after jumping out of
            the current wormhole.
        """
        for d in coords:
            if d.y == self.y and d.x > self.x:
                return d
        return None
        
with open('wormhole.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

NUMBER_OF_WORMHOLES = int(lines.pop(0))

wormhole_coordinates = []

for _ in range(NUMBER_OF_WORMHOLES):
    to_append = list(map(int, (lines.pop(0).split())))
    wormhole_coordinates.append(to_append)

wormhole_coordinates = sorted(wormhole_coordinates, key=lambda d: d[0])
coords = [Coord(*wormhole_coord) for wormhole_coord in wormhole_coordinates]

def allPairs(lst):
    if len(lst) < 2:
        yield []
        return
    if len(lst) % 2 == 1:
        # Handle odd length list
        for i in range(len(lst)):
            for result in allPairs(lst[:i] + lst[i+1:]):
                yield result
    else:
        a = lst[0]
        for i in range(1,len(lst)):
            pair = (a,lst[i])
            for rest in allPairs(lst[1:i]+lst[i+1:]):
                yield [pair] + rest

def pair(c):
    c1, c2 = c[0], c[1]
    c1.paired = c2
    c2.paired = c1

def pairs(s):
    l = list(s)
    
    if len(l) == 2:
        return [[(l[0], l[1])]]
    
    result = []
    i = 0
    for j in range(1,len(s)):
        rests = pairs( s - {l[i], l[j]} )
        pair = [ [(l[i],l[j])] + rest for rest in rests ]
        result += pair
    return result

pairing_list = pairs(set(coords))

count = 0
for pairing in pairing_list:
    for coords_to_pair in pairing:
        pair(coords_to_pair)
    
    trapped = False
    for coord in set(coords):
        route = set()

        while True:
            n = coord.paired
            if n in route:
                trapped = True
                break

            route.add(n)

            if n.next() is None:
                break
            else:
                coord = n.next()

        if trapped == True:
            break
    if trapped == True:
        count += 1

out = str(count)

with open('wormhole.out', 'w') as file:
    file.write(out + '\n')