x = int(input())

for i in range(x + 1, x + 100000):
    if len(set(str(i))) == len(str(i)):
        print(i)
        break
