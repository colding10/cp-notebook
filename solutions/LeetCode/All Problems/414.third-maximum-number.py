#
# @lc app=leetcode id=414 lang=python3
#
# [414] Third Maximum Number
#

# @lc code=start
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        return sorted(set(nums))[-3 if len(sorted(set(nums))) >= 3 else -1]
# @lc code=end

