#
# @lc app=leetcode id=2553 lang=python3
#
# [2553] Separate the Digits in an Array
#

# @lc code=start
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        out = []
        for i in range(len(nums)):
            digs = [int(s) for s in str(nums[i])]
            out += digs
        
        return out
# @lc code=end

