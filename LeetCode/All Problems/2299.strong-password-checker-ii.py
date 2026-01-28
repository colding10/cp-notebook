#
# @lc app=leetcode id=2299 lang=python3
#
# [2299] Strong Password Checker II
#

# @lc code=start
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        
        seen_upper = False
        seen_lower = False
        seen_special = False
        seen_digit = False
        prev_char = ""
        
        for c in password:
            if c == prev_char:
                return False
            if c.isupper():
                seen_upper = True
            if c.islower():
                seen_lower = True
            if c.isdigit():
                seen_digit = True
            if c in "!@#$%^&*()-+":
                seen_special = True
            
            prev_char = c
        
        if all((seen_upper, seen_lower, seen_special, seen_digit)):
            return True

        return False
# @lc code=end

