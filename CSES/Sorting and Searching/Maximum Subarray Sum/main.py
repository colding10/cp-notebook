import math

def maximumSumSubarray(arr, n):
     
    # Initialize minimum prefix
    # sum to 0.
    min_prefix_sum = 0
 
    # Initialize maximum subarray
    # sum so far to -infinity.
    res = -math.inf
 
    # Initialize and compute the
    # prefix sum array.
    prefix_sum = []
    prefix_sum.append(arr[0])
     
    for i in range(1, n):
        prefix_sum.append(prefix_sum[i - 1] + arr[i])    
 
    # loop through the array keep
    # track of minimum prefix sum
    # so far and maximum subarray
    # sum.
    for i in range(n):
         
        res = max(res, prefix_sum[i] - min_prefix_sum)
        min_prefix_sum = min(min_prefix_sum, prefix_sum[i])
     
    return res

n = int(input())
numbers = list(map(int, input().split()))
print(maximumSumSubarray(numbers, n))
