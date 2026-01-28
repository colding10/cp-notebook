"""
7. Reverse Integer
MEDIUM
FULLY ACCEPTED
"""

import sys

class Solution:
    def reverse(self, x: int) -> int:
        o_n = str(x)
        n = int(o_n.replace('-', ''))
        
        r = 0
        while(n > 0):
            a = n % 10
            r = r * 10 + a
            n = n // 10
        
        if abs(r) > 2 ** 31 - 1:
            r = 0

        return r * -1 if '-' in o_n else r