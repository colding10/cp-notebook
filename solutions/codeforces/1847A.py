def find_minimum_power(t, test_cases):
    for _ in range(t):
        n, k, a = test_cases[_]
        differences = [abs(a[i] - a[i + 1]) for i in range(n - 1)]
        differences.sort(reverse=True)
        power_sum = sum(differences[: k - 1])
        total_power = sum(differences) - power_sum
        print(total_power)


t = int(input())
test_cases = []
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    test_cases.append((n, k, a))

find_minimum_power(t, test_cases)
