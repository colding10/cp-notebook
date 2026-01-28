#
# @lc app=leetcode id=1652 lang=python3
#
# [1652] Defuse the Bomb
#

# @lc code=start
class Solution:
    def next_k_sum(self, array: List[int], start: int, k: int) -> int:
        out = 0
        length = len(array)
        
        for i in range(start+1, start+k+1):
            i = i % length
            out += array[i]
        
        return out
    
    def prev_k_sum(self, array: List[int], start: int, k):
        out = 0
        i = start - 1
        for _ in range(k):
            out += array[i]
            i -= 1
        
        return out
    
    def decrypt(self, code: List[int], k: int) -> List[int]:
        new = [0] * len(code)
        
        if k == 0:
            return new
        if k < 0:
            for i in range(len(code)):
                new[i] = self.prev_k_sum(code, i, k)
            return new
        if k > 0:
            for i in range(len(code)):
                new[i] = self.next_k_sum(code, i, k)
            return new
            
# @lc code=end

