"""
4. Median of Two Sorted Arrays
HARD
"""

import statistics

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums3 = sorted(nums1 + nums2)

        return statistics.median(nums3)