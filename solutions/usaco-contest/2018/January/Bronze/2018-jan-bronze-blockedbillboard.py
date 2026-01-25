import sys

sys.stdin = open('billboard.in', 'r')
sys.stdout = open('billboard.out', 'w')

class Rectangle(object):
    def __init__(self, coords):
        self.x1, self.y1, self.x2, self.y2 = coords
        
    @property
    def area(self):
        return abs(self.x2 - self.x1) * abs(self.y2 - self.y1)
    

def intersectionArea(r1, r2):
	x_overlap = max(0, min(r1.x2, r2.x2) - max(r1.x1, r2.x1))
	y_overlap = max(0, min(r1.y2, r2.y2) - max(r1.y1, r2.y1))

	return x_overlap * y_overlap

rects = []
for _ in range(3):
    coords = list(map(int, input().strip().split()))
    rects.append(Rectangle(coords))

out = rects[0].area + rects[1].area - intersectionArea(rects[0], rects[2]) - intersectionArea(rects[1], rects[2])

print(out)