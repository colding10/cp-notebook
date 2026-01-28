#
# @lc app=leetcode id=2239 lang=python3
#
# [2239] Find Closest Number to Zero
#

# @lc code=start
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        best = float('inf')
        nums.sort()
        for n in nums:
            if abs(n) <= abs(best):
                best = n
        
        return best
# @lc code=end

