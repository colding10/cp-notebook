#
# @lc app=leetcode id=65 lang=python3
#
# [65] Valid Number
#

# @lc code=start
class Solution:
    def isNumber(self, s: str) -> bool:
        if s == '':
            return True
        if s == '.':
            return False
        
        seen_sign = False
        seen_int_portion = False
        seen_dot = False
        seen_float_portion = False
        seen_e = False
        seen_e_portion = False
        
        for i, char in enumerate(s):
            if i == 0 and char in "+-":
                seen_sign = True
                continue
            
            if char in "abcdfghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ":
                return False
            
            if char in "+-":
                if seen_e and not seen_e_portion:
                    continue
                return False
            
            if char in "0123456789":
                if not seen_int_portion:
                    seen_int_portion = True
                if seen_dot:
                    seen_float_portion = True
                if seen_e:
                    seen_e_portion = True
                continue
        
            if char == ".":
                if seen_dot:
                    return False
                if seen_e:
                    return False
                # if not seen_int_portion:
                #     return False
                seen_dot = True
                continue
            
            if char in "eE":
                if seen_e:
                    return False
                if not seen_int_portion:
                    return False
                seen_e = True
                continue
            
        
        if seen_sign and not seen_int_portion:
            return False
        if seen_dot and not seen_float_portion and seen_e:
            return False
        if seen_e and not seen_e_portion:
            return False
    
        return True
            
            
# @lc code=end

