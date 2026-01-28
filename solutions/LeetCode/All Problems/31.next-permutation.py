#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
#

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        """
        Find the highest index i such that s[i] < s[i+1]. If no such index exists, the permutation is the last permutation.
Find the highest index j > i such that s[j] > s[i]. Such a j must exist, since i+1 is such an index.
Swap s[i] with s[j].
Reverse the order of all of the elements after index i till the last element.
"""

        biggest = -1
        
        for i in range(len(nums) - 1):
            if nums[i] < nums[i+1]:
                biggest = i
        
        if biggest == -1:
            nums.sort()
            return
        
        j = -1
        
        for i in range(biggest +1, len(nums)):
            if nums[i] > nums[biggest]:
                j = i
        
        nums[i], nums[j] = nums[j], nums[i]
        nums[i:] = nums[i:][::-1]
        
# @lc code=end

