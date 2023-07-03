def min_carrots_to_destination(x, y, a, b, c):
    jump_costs = [a, b, c]
    jump_costs.sort()
    
    if jump_costs[0] + jump_costs[1] <= jump_costs[2]:
        return x * jump_costs[0] + y * jump_costs[1]
    else:
        min_cost = (x + y) * jump_costs[0]
        if x > y:
            min_cost += (x - y) * jump_costs[2]
        else:
            min_cost += (y - x) * jump_costs[2]
        return min_cost

# Read the number of test cases
t = int(input())

# Process each test case
for _ in range(t):
    x, y, a, b, c = map(int, input().split())
    result = min_carrots_to_destination(x, y, a, b, c)
    print(result)
