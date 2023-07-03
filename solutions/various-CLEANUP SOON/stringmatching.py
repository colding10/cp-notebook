from sys import stdin, stdout

a = stdin.readline().strip()
b = stdin.readline().strip()

print(f'{a=}')
print(f'{b=}')

ans = a.count(b)

stdout.write(f'{ans}\n')
