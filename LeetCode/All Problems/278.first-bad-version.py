#
# @lc app=leetcode id=278 lang=python3
#
# [278] First Bad Version
#

# @lc code=start
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        lower = 1
        upper = n
        
        while lower <= upper:
            mid = (upper + lower) // 2
            
            if isBadVersion(mid):
                upper = mid - 1
            else:
                lower = mid + 1
        
        return lower
# @lc code=end

