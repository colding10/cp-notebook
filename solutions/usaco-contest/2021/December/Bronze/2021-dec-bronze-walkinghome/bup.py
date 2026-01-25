

def validate_case(board, sequence, change_limit):
    i, j = 0, 0
    change_count = 0
    previous = None

    for move in sequence:
        if move == DOWN:
            if previous is None:
                previous = DOWN
            else:
                if move != previous:
                    change_count += 1
                previous = DOWN

            i += 1
        else:
            if previous is None:
                previous = RIGHT
            else:
                if move != previous:
                    change_count += 1
                previous = RIGHT

            j += 1

        # print(f"{i=}, {j=}, {change_count=}")

        if change_count > change_limit:
            return False
        if board[i][j] == "H":
            return False

    return True


def generate_possible(board):
    return set(permutations([DOWN] * (len(board) - 1) + [RIGHT] * (len(board) - 1)))


def solve(board, change_limit):
    count = 0

    for case in generate_possible(board):
        if validate_case(board, case, change_limit):
            count += 1

    return count
