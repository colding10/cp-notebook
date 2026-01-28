# Constants for the space size
WIDTH = 101
HEIGHT = 103

# Read input from file
with open("input.txt", "r") as file:
    robots = []
    for line in file:
        line = line.strip()
        if line:
            p, v = line.split(" ")
            px, py = map(int, p[2:].split(","))
            vx, vy = map(int, v[2:].split(","))
            robots.append(((px, py), (vx, vy)))


def generate_grid(robots):
    """Creates a grid representing robot positions."""
    grid = [["." for _ in range(WIDTH)] for _ in range(HEIGHT)]
    for x, y in robots:
        grid[y][x] = "#"
    return grid


def find_pattern(grid, pattern="###############################"):
    """Checks if the pattern appears in any row of the grid."""
    for row in grid:
        if pattern in "".join(row):
            return True
    return False


# Simulate robot positions over time
for seconds in range(20000):  # Adjust max seconds as needed
    positions = []
    for (px, py), (vx, vy) in robots:
        # Calculate new positions with wrapping
        new_x = (px + vx * seconds) % WIDTH
        new_y = (py + vy * seconds) % HEIGHT
        positions.append((new_x, new_y))

    # Generate the grid
    grid = generate_grid(positions)

    # Check for the pattern
    if find_pattern(grid):
        print(f"Pattern found at {seconds} seconds")
        for row in grid:
            print("".join(row))
