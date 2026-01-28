#
# @lc app=leetcode id=682 lang=python3
#
# [682] Baseball Game
#

# @lc code=start
class Solution:
    def calPoints(self, operations: List[str]) -> int:
        score = []
        for o in operations:
            try:
                score.append(int(o))
            except:   
                if o == "+":
                    score.append(sum(score[-2:]))
                if o == "D":
                    score.append(score[-1] * 2)
                if o == "C":
                    score.pop(-1)
        
        return sum(score)
# @lc code=end

