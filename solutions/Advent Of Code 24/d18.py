import heapq

def parse_input(file_path):
    with open(file_path, 'r') as f:
        lines = f.readlines()
    return [tuple(map(int, line.strip().split(','))) for line in lines]

def is_path_available(grid, start, goal):
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    n = len(grid)
    heap = [(0, start)]  # (steps, (x, y))
    visited = set()
    
    while heap:
        _, (x, y) = heapq.heappop(heap)
        if (x, y) == goal:
            return True
        if (x, y) in visited:
            continue
        visited.add((x, y))
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n and grid[ny][nx] == 0:
                heapq.heappush(heap, (0, (nx, ny)))
    
    return False

def find_blocking_byte(grid_size, byte_positions):
    grid = [[0] * grid_size for _ in range(grid_size)]
    start, goal = (0, 0), (grid_size - 1, grid_size - 1)
    
    for idx, (x, y) in enumerate(byte_positions):
        grid[y][x] = 1  # Mark as corrupted
        if not is_path_available(grid, start, goal):
            return f"{x},{y}"

def main():
    input_file = 'input.txt'
    byte_positions = parse_input(input_file)
    grid_size = 71  # Memory grid dimensions
    result = find_blocking_byte(grid_size, byte_positions)
    print(result)

if __name__ == "__main__":
    main()