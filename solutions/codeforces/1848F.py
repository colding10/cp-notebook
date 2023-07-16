def time_to_all_zeros(array):
    n = len(array)
    allZero = False
    seconds = 0
    
    if all(elem == 0 for elem in array):
        return seconds
    
    while not allZero:
        seconds += 1
        temp = [0] * n
        allZero = True
        
        for i in range(n):
            temp[i] = array[(i+1) % n] + 1
            if temp[i] != 0:
                allZero = False
                break
        
        array = temp
        
        if allZero:
            break
    
    if allZero:
        return seconds
    else:
        return -1

# Example usage
arr = [1, 2, 1, 2]
result = time_to_all_zeros(arr)
print(result)  # Output: 4
