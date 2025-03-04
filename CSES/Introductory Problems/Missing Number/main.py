N = int(input())
numbers = list(map(int, input().split()))

missing = int((N + 1) * (N/2) - sum(numbers))
print(missing)