def count_pairs(n, a):
    import bisect
    
    # Prepare the position array where pos[value] is the index of `value` in permutation `a`
    pos = [0] * (n + 1)
    for index in range(n):
        pos[a[index]] = index
    
    count = 0
    
    # Iterate over all possible values of `a_j`
    for j in range(n):
        aj = a[j]
        
        # For each a_j, we need to check all possible `a_i` where `a_i + a_j = a_{i + a_j}`
        # That is, `a_i = a_{i + a_j} - a_j`
        # We need to find `i` such that:
        #   `a_i = a_{i + a_j} - a_j`
        for value in range(1, n + 1):
            target_index = pos[value]
            if target_index - aj >= 0 and a[target_index - aj] == value - aj:
                count += 1
    
    return count

# Example usage
n = int(input().strip())
a = list(map(int, input().strip().split()))
print(count_pairs(n, a))
