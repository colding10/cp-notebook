def solve_equation(n, x):
    # Check if x is within the possible range
    if x < -n*(n+1)//2 or x > n*(n+1)//2:
        return "IMPOSSIBLE"
    
    # Initialize the equation as an empty string
    equation = ""
    
    # If x is negative, reverse the signs
    if x < 0:
        x = -x
        equation += "-"
    
    # Add the numbers from 1 to n-1 to the equation
    for i in range(1, n):
        equation += str(i) + "+"
        x -= i
    
    # Add the remaining number n to the equation
    equation += str(n) + "-" + str(x)
    
    return equation

# Read the input values
n, x = map(int, input().split())

# Solve the equation and print the result
print(solve_equation(n, x))
