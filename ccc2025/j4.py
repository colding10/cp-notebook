from itertools import groupby

n = int(input())
weather = [input().strip() for _ in range(n)]

groups = [(key, len(list(group))) for key, group in groupby(weather)]

if len(groups) == 2:
    if groups[0][0] == "S":
        print(groups[0][1] + 1)
    else:
        print(groups[1][1] + 1)
    quit()
if len(groups) == 1:
    if groups[0][0] == "S":
        print(groups[0][1] - 1)
    else:
        print("1")
    quit()

max_sunny_streak = groups[0][1] + 1 if groups[0][0] == 'S' else 0
max_sunny_streak = max(max_sunny_streak, groups[1][1] + 1) if groups[1][0] == 'S' else max_sunny_streak

# print(groups)
# print()
# print()

for i in range(2, len(groups)):
    if groups[i][0] == 'S' and groups[i - 1][0] == 'P' and groups[i-1][1] == 1 and groups[i - 2][0] == "S":
        max_sunny_streak = max(groups[i][1] + groups[i-2][1] + 1, max_sunny_streak)
    if groups[i][0] == 'S':
        max_sunny_streak = max(max_sunny_streak, groups[i][1] + 1) 

print(max_sunny_streak)