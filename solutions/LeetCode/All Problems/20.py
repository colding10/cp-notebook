"""
20. Valid Parentheses
EASY
"""

class Solution:
    def isValid(self, s: str) -> bool:
        opening = list("({[")
        closing = list(")}]")

        seen = []
        for c in s:
            if c in opening:
                seen.append(c)
            elif c in closing:
                if not seen:
                    return False
                if opening.index(seen[-1]) != closing.index(c):
                    return False
                seen.pop(-1)
        
        if seen:
            return False
        return True