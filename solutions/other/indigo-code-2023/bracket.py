n = int(input())
s = list(input().strip())
e = []
for c in s:
    e.append(c)
    e.append('?')
    
def balanced(expr):
    stack = []

    for char in expr:
        if char == "(":
            stack.append(char)
        else:
            if not stack:
                return False
            current_char = stack.pop()
            if current_char == '(':
                if char != ")":
                    return False
 
    if stack:
        return False
    return True

count = 0

def recurse(expr):
    global count
    if "?" not in expr:
        if balanced(expr):
            count += 1
        return
    
    missing_idx = expr.index('?')
    
    if expr[:missing_idx].count(')') > expr[:missing_idx].count('('):
        return
    
    e1 = list(expr)
    e2 = list(expr)
    
    e1[missing_idx] = ')'
    e2[missing_idx] = '('
    
    recurse(e1)
    recurse(e2)

recurse(e)
print(count)