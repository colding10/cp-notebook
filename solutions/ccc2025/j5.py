R = int(input())
C = int(input())
M = int(input())

prev_row = [c % M + 1 for c in range(C)]  # Store only one row at a time

for r in range(1, R):
    curr_row = [float('inf')] * C
    for c in range(C):
        cost = (C * r + c) % M + 1

        min_prev = prev_row[c]  # From above
        if c > 0:
            min_prev = min(min_prev, prev_row[c-1])  # From top-left diagonal
        if c < C - 1:
            min_prev = min(min_prev, prev_row[c+1])  # From top-right diagonal
        curr_row[c] = cost + min_prev
    prev_row = curr_row  # Move to the next row

print(min(prev_row))