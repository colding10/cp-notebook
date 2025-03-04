from collections import defaultdict

def read_map(file_path):
    with open(file_path, "r") as f:
        return [list(map(int, line.strip())) for line in f]

def is_valid_move(map_data, x, y, next_x, next_y):
    if 0 <= next_x < len(map_data) and 0 <= next_y < len(map_data[0]):
        return map_data[next_x][next_y] == map_data[x][y] + 1
    return False

def count_distinct_trails(map_data, x, y, memo):
    """Count distinct hiking trails starting at (x, y) using DFS with memoization."""
    if map_data[x][y] == 9:
        return 1

    if (x, y) in memo:
        return memo[(x, y)]

    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    trail_count = 0

    for dx, dy in directions:
        next_x, next_y = x + dx, y + dy
        if is_valid_move(map_data, x, y, next_x, next_y):
            trail_count += count_distinct_trails(map_data, next_x, next_y, memo)

    memo[(x, y)] = trail_count
    return trail_count

def compute_total_rating(file_path):
    map_data = read_map(file_path)
    total_rating = 0
    memo = {}

    for x in range(len(map_data)):
        for y in range(len(map_data[0])):
            if map_data[x][y] == 0:
                total_rating += count_distinct_trails(map_data, x, y, memo)

    return total_rating

if __name__ == "__main__":
    file_path = "input.txt"
    total_rating = compute_total_rating(file_path)
    print("Total rating of all trailheads:", total_rating)