#
# @lc app=leetcode id=43 lang=python3
#
# [43] Multiply Strings
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        l1 = list(map(int, num1[::-1]))
        l2 = list(map(int, num2[::-1]))

        res = [0] * (len(l1) + len(l2))

        for i in range(len(l1)):
            for j in range(len(l2)):
                res[i+j] += l1[i] * l2[j]

        for i in range(len(res) - 1):
            res[i+1] += res[i] // 10
            res[i] %= 10

        while len(res) > 1 and res[-1] == 0:
            res.pop()

        return "".join(map(str, res[::-1]))

# @lc code=end
