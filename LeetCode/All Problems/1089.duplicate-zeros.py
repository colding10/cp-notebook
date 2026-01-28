#
# @lc app=leetcode id=1089 lang=python3
#
# [1089] Duplicate Zeros
#

# @lc code=start
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        for i in range(len(arr)):
            if arr[i] == 0:
                arr[i] = [0, 0]

        arr = eval("[" + str(arr).replace("[", "").replace("]", "") + "]")


# @lc code=end
