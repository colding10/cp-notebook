import bisect


def calculate_value(a, pairs):
    n = len(a)
    multipliers = list(range(1, n+1))
    sorted_a = sorted(a)

    for i, j in pairs:
        i -= 1
        
        new_a = list(sorted_a)
        new_a.remove(a[i])
        bisect.insort(new_a, j)
        
        sum = 0
        for k in range(n):
            sum += new_a[k] * multipliers[k]

        print(sum) # print or return sum for each input

n = int(input())
a = list(map(int, input().split()))
TC = int(input())
pairs = [
    list(map(int, input().split()))
    for _ in range(TC)
]

calculate_value(a, pairs)