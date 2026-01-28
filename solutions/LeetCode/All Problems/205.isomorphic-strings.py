#
# @lc app=leetcode id=205 lang=python3
#
# [205] Isomorphic Strings
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_id = 0
        t_id = 0
        
        s_map = []
        t_map = []
        
        s_seen = {}
        t_seen = {}
        
        for c in s:
            if c not in s_seen:
                s_id += 1
                s_seen[c] = s_id
                
            
            s_map.append(s_seen[c])
        
        for c in t:
            if c not in t_seen:
                t_id += 1
                t_seen[c] = t_id
            
            t_map.append(t_seen[c])
        
        return s_map == t_map
# @lc code=end

