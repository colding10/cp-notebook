from dataclasses import dataclass


# Load and preprocess the grid
def load_grid(file_name):
    grid = []
    start = None
    with open(file_name, "r") as f:
        for i, line in enumerate(f.readlines()):
            row = line.strip()
            if "^" in row:
                start = (i, row.find("^"))
                row = row.replace("^", ".")
            grid.append(row)
    return grid, start


grid, start = load_grid("input.txt")
n, m = len(grid), len(grid[0])  # Grid dimensions


@dataclass(frozen=True)
class Pos:
    i: int
    j: int

    def __add__(self, other):
        return Pos(self.i + other.i, self.j + other.j)

    def __eq__(self, other):
        return isinstance(other, Pos) and (self.i, self.j) == (other.i, other.j)

    def __hash__(self):
        return hash((self.i, self.j))

    def rotate_right(self):
        return Pos(self.j, -self.i)


# Check if a position is within grid bounds
def is_inbounds(pos):
    return 0 <= pos.i < n and 0 <= pos.j < m


# Simulate the guard's path and determine the visited area
def simulate_guard_path(new_obstacle=None):
    pos = Pos(start[0], start[1])
    direction = Pos(-1, 0)  # Initial direction: up
    visited = set()
    states = {(pos, direction)}

    while is_inbounds(pos):
        visited.add(pos)
        next_pos = pos + direction

        if is_inbounds(next_pos) and (
            grid[next_pos.i][next_pos.j] == "#" or next_pos == new_obstacle
        ):
            direction = direction.rotate_right()
        else:
            pos = next_pos

        new_state = (pos, direction)
        if new_state in states:  # Check for cycle
            return True, visited
        states.add(new_state)

    return False, visited


# Part 1: Calculate the number of unique cells visited
visited_cells = simulate_guard_path()[1]
print("Unique cells visited:", len(visited_cells))


# Part 2: Count obstacles that create cycles
def count_cycle_inducing_obstacles(visited_cells):
    count = 0
    obstacle_candidates = visited_cells - {Pos(start[0], start[1])}

    for obstacle in obstacle_candidates:
        if simulate_guard_path(obstacle)[0]:  # Cycle occurs
            count += 1

    return count


cycle_inducing_obstacles = count_cycle_inducing_obstacles(visited_cells)
print("Cycle-inducing obstacles:", cycle_inducing_obstacles)
