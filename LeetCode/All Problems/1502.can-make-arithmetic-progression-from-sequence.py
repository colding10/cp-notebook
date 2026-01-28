#
# @lc app=leetcode id=1502 lang=python3
#
# [1502] Can Make Arithmetic Progression From Sequence
#

# @lc code=start
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        for i, v in enumerate(arr):
            if 0 < i < len(arr) - 1:
                if v - arr[i-1] != arr[i+1] - arr[i]:
                    return False
        
        return True
# @lc code=end

