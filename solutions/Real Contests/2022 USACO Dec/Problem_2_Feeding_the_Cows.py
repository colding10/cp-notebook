from sys import stdin, stdout


def minimum_patches(cows, k):
    patches = ["."] * len(cows)
    patch_count = 0
    last_patch_h = -float("inf")
    last_past_g = -float("inf")

    for i in range(len(cows)):
        if cows[i] == "G":
            if last_past_g < i - k:
                patch_count += 1
                last_past_g = i
                patches[i] = "G"
        else:
            if last_patch_h < i - k:
                patch_count += 1
                last_patch_h = i
                patches[i] = "H"

    return patch_count, "".join(patches)


t = int(stdin.readline())

for _ in range(t):
    n, k = map(int, stdin.readline().rstrip().split())
    cows = str(stdin.readline().rstrip())

    ans = minimum_patches(cows, k)
    stdout.write("{}\n{}\n".format(ans[0], ans[1]))
