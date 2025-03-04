from sys import stdin, stdout



def minimum_patches(cows, k):
    N = len(cows)
    reachs = {i: {"G": 0, "H": 0} for i in range(N)}

    for i in range(N):
        in_reach = cows[max(0, i - k) : min(N - 1, i + k)]
        reachs[i]["G"] += in_reach.count("G")
        reachs[i]["H"] += in_reach.count("H")

    best_g = max(reachs.items(), key = lambda d: d[1]["G"])
    best_h = max(reachs.items(), key = lambda d: d[1]["H"])
    
    print(best_g, best_h)

t = int(stdin.readline())

for _ in range(t):
    n, k = map(int, stdin.readline().rstrip().split())
    cows = str(stdin.readline().rstrip())

    ans = minimum_patches(cows, k)
    stdout.write(f"{ans[0]}\n{ans[1]}\n")
