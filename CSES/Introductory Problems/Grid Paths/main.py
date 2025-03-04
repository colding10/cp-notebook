import sys
from copy import deepcopy

count = 0

def recurse(index, info, location, visited):
    global count
    res = 0
    
    if not (0 <= location[0] <= 6) or not (0 <= location[1] <= 6):
        return 0 # ran into edge
    elif location == (6, 0):
        return 1
    elif visited[location]:
        return 0 # already visited here
    
    
    visited[location] = True
    
    if info[index] == '?':
        go_left = go_down = go_up = go_right = location.copy()
        
        go_up[0] -= 1
        go_down[0] += 1
        go_left[1] -= 1
        go_right[1] += 1
        
        
        res = recurse(index + 1, info, go_up, visited)
        if res:
            count += 1
        else:
            
    
    return res