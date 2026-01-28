import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**6)

DIRECTIONS = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def read_input(file_path):
    with open(file_path, "r") as f:
        return [line.strip() for line in f]


def calculate_area_and_perimeter(grid, start, seen, directions):
    rows, cols = len(grid), len(grid[0])
    queue = deque([start])
    area = 0
    perimeter = 0
    edge_map = defaultdict(set)

    while queue:
        r, c = queue.popleft()
        if (r, c) in seen:
            continue
        seen.add((r, c))
        area += 1

        for dr, dc in directions:
            rr, cc = r + dr, c + dc
            if 0 <= rr < rows and 0 <= cc < cols and grid[rr][cc] == grid[r][c]:
                queue.append((rr, cc))
            else:
                perimeter += 1
                edge_map[(dr, dc)].add((r, c))

    return area, perimeter, edge_map


def calculate_sides(edge_map, directions):
    sides = 0
    for direction, cells in edge_map.items():
        seen_edges = set()
        for r, c in cells:
            if (r, c) in seen_edges:
                continue
            sides += 1
            queue = deque([(r, c)])
            while queue:
                cr, cc = queue.popleft()
                if (cr, cc) in seen_edges:
                    continue
                seen_edges.add((cr, cc))
                for dr, dc in directions:
                    nr, nc = cr + dr, cc + dc
                    if (nr, nc) in cells:
                        queue.append((nr, nc))
    return sides


def main():
    grid = read_input("input.txt")
    rows, cols = len(grid), len(grid[0])
    seen = set()
    total_area_perimeter = 0
    total_area_sides = 0

    for r in range(rows):
        for c in range(cols):
            if (r, c) in seen:
                continue
            area, perimeter, edge_map = calculate_area_and_perimeter(
                grid, (r, c), seen, DIRECTIONS
            )
            sides = calculate_sides(edge_map, DIRECTIONS)
            total_area_perimeter += area * perimeter
            total_area_sides += area * sides

    print(total_area_perimeter)
    print(total_area_sides)


if __name__ == "__main__":
    main()
