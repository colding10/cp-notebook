def count_ways(design, patterns):
    n = len(design)
    dp = [0] * (n + 1)
    dp[0] = 1  # Base case: one way to construct an empty string
    
    for i in range(1, n + 1):
        for pattern in patterns:
            if design[:i].endswith(pattern):
                dp[i] += dp[i - len(pattern)]
    
    return dp[n]

def total_arrangements(input_file):
    with open(input_file, 'r') as file:
        lines = file.read().strip().split('\n')
    
    # Parse input
    towel_patterns = lines[0].split(", ")
    designs = lines[2:]
    
    # Sum the number of ways each design can be constructed
    total_ways = sum(count_ways(design, towel_patterns) for design in designs)
    return total_ways

# Run the function and print the result
input_file = 'input.txt'
result = total_arrangements(input_file)
print(result)