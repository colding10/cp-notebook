def is_glimmery(pond, k):
    n = len(pond)
    m = len(pond[0])

    for i in range(n - k + 1):
        for j in range(m - k + 1):
            count = 0
            for x in range(i, i + k):
                for y in range(j, j + k):
                    count += pond[x][y]

            if count % 2 == 0:
                return "true"

    return "false"

# Read input values
n, m, k = map(int, input().split())
pond = []
for _ in range(n):
    row = list(map(int, input().split()))
    pond.append(row)

# Check if the pond is glimmery
result = is_glimmery(pond, k)

# Print the result
print(result)
