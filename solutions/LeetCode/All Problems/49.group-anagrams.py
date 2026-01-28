#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
class Solution:
    def hash(self, s: str) -> int:
        primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131]

        out = 1
        for c in s:
            out ^= primes[ord(c) % 32]
        return out

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapped = {}
        for s in strs:
            val = self.hash(s)
            if val in mapped:
                mapped[val].append(s)
            else:
                mapped[val] = [s]
        
        return list(mapped.values())
# @lc code=end

