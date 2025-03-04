chars = input()

current_char = chars[0]
maximum_count = 0
current_count = 0

for char in chars:
    if char == current_char:
        current_count += 1
    else:
        if current_count > maximum_count:
            maximum_count = current_count
        current_count = 1
        current_char = char
if current_count > maximum_count:
    maximum_count = current_count
    
print(maximum_count)