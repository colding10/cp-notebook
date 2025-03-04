from sys import stdin, stdout

def solve(blocks, word):
    if len(word) == 0:
        return True
    
    letter = word[0]
    
    for block in blocks:
        if letter in block:
            b = list(blocks)
            b.remove(block)
            
            if solve(b, word[1:]):
                return True
            
    return False

t = int(stdin.readline())
blocks = [stdin.readline().strip() for _ in range(4)]

result_mapping = {True: "YES", False: "NO"}

for _ in range(t):
    word = stdin.readline().strip()
    stdout.write(f"{result_mapping[solve(blocks, word)]}\n")
