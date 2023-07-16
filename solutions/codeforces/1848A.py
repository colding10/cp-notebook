from collections import deque


def is_valid_room(n, m, x, y):
    return 1 <= x <= n and 1 <= y <= m


def can_escape(t, test_cases):
    results = []
    for _ in range(t):
        n, m, k = map(int, test_cases[_][0].split())
        x, y = map(int, test_cases[_][1].split())
        friends = []
        for i in range(k):
            xi, yi = map(int, test_cases[_][i + 2].split())
            friends.append((xi, yi))

        visited = set()
        queue = deque([(x, y)])
        escape = True

        while queue:
            vx, vy = queue.popleft()
            visited.add((vx, vy))

            if all((abs(vx - fx) + abs(vy - fy)) != 1 for fx, fy in friends):
                # Vika has found an escape route
                escape = True
                break

            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = vx + dx, vy + dy
                if is_valid_room(n, m, nx, ny) and (nx, ny) not in visited:
                    queue.append((nx, ny))
                    visited.add((nx, ny))
                    if (nx, ny) in friends:
                        friends.remove((nx, ny))  # Remove visited friends

            if not friends:
                # All friends have been visited, Vika can escape
                escape = True
                break

        if escape:
            results.append("YES")
        else:
            results.append("NO")

    return results


# Example usage
test_cases = [
    ["2 2 1", "1 1", "1 2"],
    ["2 2 2", "1 1", "2 2", "2 2"],
    ["1 2 1", "1 1", "1 2"],
    ["5 5 4", "3 3", "1 1", "1 5", "5 1", "5 5"],
    ["2 2 2", "1 1", "2 1", "1 2"],
    ["3 4 1", "1 2", "3 3"]
]

results = can_escape(6, test_cases)
for result in results:
    print(result)
