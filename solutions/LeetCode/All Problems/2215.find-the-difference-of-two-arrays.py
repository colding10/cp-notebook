#
# @lc app=leetcode id=2215 lang=python3
#
# [2215] Find the Difference of Two Arrays
#

# @lc code=start
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        ans = [[], []]
        for n in nums1:
            if n not in nums2 and n not in ans[0]:
                ans[0].append(n)
        for n in nums2:
            if n not in nums1 and n not in ans[1]:
                ans[1].append(n)
        
        return ans
# @lc code=end

