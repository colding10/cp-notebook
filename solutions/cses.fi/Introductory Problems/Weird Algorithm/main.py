def algorithm(n):
    return n * 3 + 1 if n % 2 else n / 2

N = int(input())

while N != 1:
    print(N, end = ' ')
    N = int(algorithm(N))

print(1)