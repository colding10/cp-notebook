def minimum_button_presses(n):
    # Create a list to store the minimum button presses for each number from 1 to n
    dp = [0] * (n + 1)

    for i in range(2, n + 1):
        # If i is odd, use button B to reach (i-1)/2, then use button A to reach i
        if i % 2 == 1:
            dp[i] = dp[(i - 1) // 2] + 2
        # If i is even, use button A to reach i/2
        else:
            dp[i] = dp[i // 2] + 1

    return dp[n]

# Example usage
n = int(input())
min_presses = minimum_button_presses(n)
print(f"The minimum number of button presses required to reach {n} is {min_presses}.")
