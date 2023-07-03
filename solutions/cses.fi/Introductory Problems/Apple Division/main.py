N = int(input().strip())
apples = list(map(int, input().strip().split()))

def solve(index, set1sum, set2sum):
    if index == N:
        return abs(set1sum - set2sum)
    
    return min(solve(index + 1, set1sum + apples[index], set2sum),
               solve(index + 1, set1sum, set2sum + apples[index]))

print(solve(0, 0, 0))