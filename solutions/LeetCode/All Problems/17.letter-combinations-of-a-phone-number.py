#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#

# @lc code=start
class Solution:
    out = []
    m = {x: tuple(chr(i) for i in range(91+(x*3), 94+(x*3))) for x in range(2, 10)}
    
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) != 0:
            
        
        
        
        
# @lc code=end

