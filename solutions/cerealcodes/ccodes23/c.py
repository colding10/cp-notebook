# Read the number of test cases
t = int(input())

for _ in range(t):
    # Read the number of red pandas
    n = int(input())
    
    # Read the positions of red pandas
    p = list(map(int, input().split()))
    
    # Read the distances matrix
    d = []
    for _ in range(n):
        d.append(list(map(int, input().split())))
    
    # Calculate the sum of distances for each red panda
    sum_distances = [(sum(d[i]), p[i]) for i in range(n)]
    
    # Sort red pandas based on the sum of distances
    sorted_pandas = sorted(sum_distances, reverse=true)
    
    # Print the panda positions from the sorted list
    for panda in sorted_pandas:
        print(panda[1], end=" ")
    
    print()  # Print a newline for the next test case
