#
# @lc app=leetcode id=500 lang=python3
#
# [500] Keyboard Row
#

# @lc code=start
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        
        out = []
        for word in words:
            for row in rows:
                good = True
                for c in word.lower():
                    if c not in row:
                        good = False
                        break
                if good:
                    out.append(word)
                    break
        
        return out
# @lc code=end

