'''
ID: colindi1
LANG: PYTHON3
TASK: transform
'''

# define transformation functions and then
# run through each by check if a statement is true

with open ('transform.in', 'r') as file:
    lines = [line.replace('\n', '') for line in file.readlines()]

N = int(lines.pop(0))


original = []
new = []

for _ in range(N):
    original.append(list(lines.pop(0)))

og = original.copy()

for _ in range(N):
    new.append(list(lines.pop(0)))

def rotate(orig, degrees): #rotated degrees
    rotated = orig.copy()
    for _ in range(int(degrees/90)):
        rotated = list(zip(*rotated[::-1]))
    return [list(i) for i in rotated]

def reflection(m): #reflected horizontally or vertically
    tempm = m.copy()
    for i in range(0,len(tempm),1):
            tempm[i].reverse()

    return [list(i) for i in tempm]

rotation_90 = rotate(original, 90)
rotation_180 = rotate(original, 180)
rotation_270 = rotate(original, 270)
reflection_orig = reflection(original)

if rotation_90 == new:
    out = '1'
elif rotation_180 == new:
    out = '2'
elif rotation_270 == new:
    out = '3'
elif reflection_orig == new:
    out = '4'
elif new in [rotate(reflection_orig, 90), rotate(reflection_orig, 180), rotate(reflection_orig, 270)]:
    out = '5'
elif original == new:
    out = '6'
else:
    out = '7'

with open('transform.out', 'w') as file:
    file.write(out + '\n')