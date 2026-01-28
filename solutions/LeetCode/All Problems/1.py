"""
1. Two Sum
EASY
FULLY ACCEPTED
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for x in nums:
            tar = target - x
            if tar in nums:
                if tar != x:
                    return nums.index(x), nums.index(tar)
                elif nums.count(x) > 1:
                    a = nums.index(x)
                    nums.remove(x)

                    return a, nums.index(tar) + 1