import sys


def is_lonely(photo):
    return photo["H"] == 1 or photo["G"] == 1


def is_safe(photo):
    return photo["H"] >= 2 and photo["G"] >= 2


def main():
    n = int(sys.stdin.readline())
    cows = list(sys.stdin.readline().strip())

    lonely_photos = 0
    current_photo = {"G": 0, "H": 0}

    for i in range(n - 2):
        current_photo = {"G": 0, "H": 0}
        current_photo[cows[i]] += 1

        for j in range(i + 1, n):
            # print(f"{i=}, {j=}")
            current_photo[cows[j]] += 1

            if sum(current_photo.values()) < 3:
                continue

            if is_safe(current_photo):
                # print(f"skipping rest of index {i=}", current_photo)
                break

            if is_lonely(current_photo):
                # print("LONELY:", current_photo)
                lonely_photos += 1

    sys.stdout.write(str(lonely_photos) + "\n")


if __name__ == "__main__":
    main()
