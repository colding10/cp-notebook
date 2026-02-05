'''
ID: colindi1
LANG: PYTHON3
TASK: runround
'''

with open('runround.in', 'r') as file:
    M = int(file.readline().strip())
    
def isRunaround(n):
    string_n = str(n)
    dict_string_n = {i:0 for i in range(len(string_n))}
    
    if len(set(string_n)) != len(string_n):
        return False
    current_index = 0
    digit = string_n[0]
    for _ in range(len(string_n) * 4):
        new_index = (current_index + int(digit)) % len(string_n)
        digit = string_n[new_index]
        dict_string_n[new_index] += 1
        current_index = new_index
        if 0 not in dict_string_n.values():
            break
    for val in dict_string_n.values():
        if val != 1:
            return False

    if digit == string_n[0]:
        return True
    return False

def getNextRunaround(n):
    for i in range(n+1, 100**100):
        if isRunaround(i):
            return i

out = str(getNextRunaround(M))

with open('runround.out', 'w') as file:
    file.write(out + '\n')