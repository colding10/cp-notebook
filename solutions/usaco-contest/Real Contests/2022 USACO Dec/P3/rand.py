from random import Random

random = Random(9196)

t = int(input())

for _ in range(t):
    print("OK" if random.randint(0, 1) else "LIE")