n, k = map(int, input().split())
nums = list(map(int, input().strip().split()))

nums.sort(reverse=True)
cutoff = nums[k-1]
print(len([x for x in nums if x >= cutoff and x > 0]))
