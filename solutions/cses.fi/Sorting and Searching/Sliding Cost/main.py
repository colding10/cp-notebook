from sys import stdin, stdout

def solve(numbers):
    target_length = numbers[len(numbers) // 2]
       
    total = sum(abs(length - target_length) for length in numbers)
    return total
    
n, k = map(int, stdin.readline().split())
nums = list(map(int, stdin.readline().split()))

window = [0, k]

for i in range(n - k + 1):
    numwindow = nums[window[0]:window[1]]
    stdout.write(f"{solve(numwindow)} ")

stdout.write('\n')
