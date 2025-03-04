import re

with open("input.txt", "r") as file:
    data = file.read()

mul_pattern = r"mul\((\d+),(\d+)\)"
do_pattern = r"do\(\)"
dont_pattern = r"don't\(\)"

mul_enabled = True
total_sum = 0

index = 0
while index < len(data):
    mul_match = re.match(mul_pattern, data[index:])
    if mul_match:
        if mul_enabled:
            x, y = map(int, mul_match.groups())
            total_sum += x * y
        index += mul_match.end() 
        continue

    if re.match(do_pattern, data[index:]):
        mul_enabled = True
        index += len("do()")
        continue

    if re.match(dont_pattern, data[index:]):
        mul_enabled = False
        index += len("don't()")
        continue

    index += 1

print(total_sum)