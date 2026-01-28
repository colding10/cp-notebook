#
# @lc app=leetcode id=383 lang=python3
#
# [383] Ransom Note
#

# @lc code=start
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        needed = {c: ransomNote.count(c) for c in set(ransomNote)}
        for c in magazine:
            if c not in needed:
                continue
            needed[c] = max(needed[c] - 1, 0)
        
        if any(needed.values()):
            return False
        return True
# @lc code=end

