from sys import stdin, stdout

stdin = open('word.in', 'r')
stdout = open('word.out', 'w')

n, k = map(int, stdin.readline().split())
words = list(stdin.readline().rstrip().split())

line_length = 0

for word in words:
    if line_length + len(word) > k:
        stdout.write("\n" + word)
        line_length = len(word)
    else:
        if line_length > 0:
            stdout.write(" ")
            
        stdout.write(word)
        line_length += len(word)

stdout.write("\n")
