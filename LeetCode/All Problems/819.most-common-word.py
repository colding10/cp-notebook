#
# @lc app=leetcode id=819 lang=python3
#
# [819] Most Common Word
#

# @lc code=start
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        punc = "!?'.;\""
        spacing = " \n\t"
        
        words = []
        word = ""
        for c in paragraph:
            if c in punc:
                continue
            if c in spacing:
                if word:
                    words.append(word)
                    word = ""
                continue
            word += c.lower()
        
        scores = {}
        
        for word in words:
            if word in banned:
                continue
            if word in scores:
                scores[word] += 1
            else:
                scores[word] = 1
        
        return max(scores.items(), key=lambda s: s[1])[0]
# @lc code=end

