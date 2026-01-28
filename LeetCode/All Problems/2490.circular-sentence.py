#
# @lc app=leetcode id=2490 lang=python3
#
# [2490] Circular Sentence
#

# @lc code=start
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split()
        for i, v in enumerate(words):
            if v[0] != words[i-1][-1]:
                return False
        
        return True
# @lc code=end

