N = int(input())
numbers = list(range(1, N + 1))

evens = [str(i) for i in numbers if not i % 2]
odds = [str(i) for i in numbers if i % 2]

if N == 1:
    print('1')
elif N in {2, 3}:
    print('NO SOLUTION')
else:
    print(' '.join(evens) + ' ' + ' '.join(odds))