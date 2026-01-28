#
# @lc app=leetcode id=66 lang=python3
#
# [66] Plus One
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        out = list(reversed(digits)) + [0]
        out[0] += 1
        for i in range(len(out)):
            if out[i] >= 10:
                out[i] -= 10
                out[i + 1] += 1

        return reversed(out) if out[-1] else reversed(out[:-1])


# @lc code=end
