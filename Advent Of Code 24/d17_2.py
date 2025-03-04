g = [2, 4, 1, 5, 7, 5, 1, 6, 0, 3, 4, 0, 5, 5, 3, 0]

def solve( p, r ):
    if p < 0:
        print( r )
        return True
    for d in range( 8 ):
        a, i = r << 3 | d, 0
        while i < len( g ):
            if   g[ i + 1 ] <= 3: o = g[ i + 1 ]
            elif g[ i + 1 ] == 4: o = a
            elif g[ i + 1 ] == 5: o = b
            elif g[ i + 1 ] == 6: o = c
            if   g[ i ] == 0: a >>= o
            elif g[ i ] == 1: b  ^= g[ i + 1 ]
            elif g[ i ] == 2: b   = o & 7
            elif g[ i ] == 3: i   = g[ i + 1 ] - 2 if a != 0 else i
            elif g[ i ] == 4: b  ^= c
            elif g[ i ] == 5: w   = o & 7; break
            elif g[ i ] == 6: b   = a >> o
            elif g[ i ] == 7: c   = a >> o
            i += 2
        if w == g[ p ] and solve( p - 1, r << 3 | d ):
            return True
    return False

solve( len( g ) - 1, 0 )