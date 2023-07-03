import sys

sys.setrecursionlimit(100000)  # Raise recursion limit as the default will error

filein = open("lightson.in", "r")
N, m = map(int, filein.readline().split())

lit_rooms = 1
visited = [[False for i in range(N)] for j in range(N)]
illuminated = [[False for i in range(N)] for j in range(N)]
switches = [[[] for i in range(N)] for j in range(N)]

# Read in light switches input
for i in range(m):
    x, y, a, b = map(int, filein.readline().split())
    switches[x - 1][y - 1].append((a - 1, b - 1))


# Checks if a room is connected to the main component
def check_connected(x, y):
    dir_x = [-1, 0, 1, 0]
    dir_y = [0, -1, 0, 1]

    # Iterate through neighbors
    for i in range(4):
        new_x = x + dir_x[i]
        new_y = y + dir_y[i]

        # Ignore neighbor if out of bounds
        if new_x < 0 or new_y < 0 or new_x > N - 1 or new_y > N - 1:
            continue

        # If a neighbor is visited, return true
        if visited[new_x][new_y]:
            return True

    # If no neighbors have been visited, return false
    return False


# Floodfill method with source room (x, y)
def floodfill(x, y):
    global lit_rooms

    # Ignore room if its out of bounds, already visited, or not lit
    if (
        x < 0
        or y < 0
        or x > N - 1
        or y > N - 1
        or visited[x][y]
        or not illuminated[x][y]
    ):
        return

    # Ignore this room if it isn't connected to main component
    # (i.e. it's inaccessible to Bessie)
    # Don't return on the starting coordinate (1, 1)
    if not check_connected(x, y) and not (x == 0 and y == 0):
        return

    # Set room to visited
    visited[x][y] = True

    dir_x = [-1, 0, 1, 0]
    dir_y = [0, -1, 0, 1]

    # Iterate through neighbors and floodfill from them
    for i in range(4):
        floodfill(x + dir_x[i], y + dir_y[i])

    # Turn on all lights from current room
    for i in range(len(switches[x][y])):
        room_x = switches[x][y][i][0]
        room_y = switches[x][y][i][1]

        # If room hasn't been lit yet, add it to our count of rooms that
        # have been lit
        if not illuminated[room_x][room_y]:
            lit_rooms += 1

        # Set room led to by switch to lit
        illuminated[room_x][room_y] = True

        # Floodfill form new room that is lit
        floodfill(room_x, room_y)


# Set the top left room to lit (since it's lit initially)
illuminated[0][0] = True

# Start floodfill from top-left room
floodfill(0, 0)

print(lit_rooms, file=open("lightson.out", "w"))
