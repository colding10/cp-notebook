"""
13. Roman to Integer
EASY
FULLY ACCEPTED
"""

class Solution:
    def romanToInt(self, s: str) -> int:
        values = {"I":1, "V":5, "X":10,"L":50, "C": 100, "D": 500, "M": 1000}
        out = 0

        for idx, char in enumerate(s):
            if idx < len(s) - 1:
                if values[char] < values[s[idx+1]]:
                    out += values[s[idx+1]] - values[char]
                    continue
            
            if idx > 0:
                if values[char] > values[s[idx-1]]:
                    continue
            out += values[char]
        
        return out