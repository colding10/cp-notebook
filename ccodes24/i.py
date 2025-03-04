def min_moves_to_transform(n, s, t):
    def letter_value(ch):
        return ord(ch) - ord('a')
    
    def reverse_letter(ch):
        val = letter_value(ch)
        return chr(ord('a') + (25 - val))
    
    def opposite_letter(ch):
        val = letter_value(ch)
        return chr(ord('a') + ((val + 13) % 26))
    
    reverse_map = [reverse_letter(chr(i + ord('a'))) for i in range(26)]
    opposite_map = [opposite_letter(chr(i + ord('a'))) for i in range(26)]
    
    def transformation_type(c1, c2):
        if c2 == reverse_map[letter_value(c1)]:
            return 'reverse'
        if c2 == opposite_map[letter_value(c1)]:
            return 'opposite'
        return None
    
    current_transformation = None
    moves = 0
    
    for i in range(n):
        trans_type = transformation_type(s[i], t[i])
        
        if trans_type:
            if trans_type != current_transformation:
                if current_transformation is not None:
                    moves += 1
                current_transformation = trans_type
        else:
            return -1
    
    if current_transformation:
        moves += 1
    
    return moves

# Reading inputs
n = int(input().strip())
s = input().strip()
t = input().strip()

# Printing the result
print(min_moves_to_transform(n, s, t))
