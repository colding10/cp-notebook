N = int(input())
numbers = list(map(int, input().split()))

moves = 0
for index in range(1, N):
    if numbers[index] < numbers[index - 1]:
        moves += numbers[index - 1] - numbers[index]
        numbers[index] = numbers[index - 1]

print(moves)