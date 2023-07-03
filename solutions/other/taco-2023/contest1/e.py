# Function to check if it's possible for the (p, q)-knight to move from (0, 0) to (x, y)
def is_possible(p, q, x, y):
    # Check if the difference between x and 0 is divisible by p, and
    # if the difference between y and 0 is divisible by q
    if x % p == 0 or  y % q == 0:
        return "YES"
    else:
        return "NO"

# Read the number of test cases
t = int(input())

# Process each test case
for _ in range(t):
    # Read p, q, x, y for each test case
    p, q, x, y = map(int, input().split())
    
    # Check if it's possible for the (p, q)-knight to move from (0, 0) to (x, y)
    result = is_possible(p, q, x, y)
    print(result)
