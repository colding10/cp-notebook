from sys import stdin, stdout


def solve(ss):
    l = len(ss)
    if l < 3:  # too short
        return -1
    if ss == "MOO":  # already done
        return 0
    if ss.startswith("MOO") or ss.endswith("MOO"): # only need to remove
        return l - 3
    if "O" not in ss[1:-1]:  # impossible
        return -1

    best_cost = float('inf')
    
    for target_o in range(1, l - 1): # try all 'o's to be in the center of our "moo"
        if ss[target_o] != "O":
            continue
        
        cost = l - 3
        if ss[target_o - 1] != "M":
            cost += 1
        if ss[target_o + 1] != "O":
            cost += 1

        best_cost = min(best_cost, cost)
    
    return best_cost


n = int(stdin.readline())

for _ in range(n):
    string = stdin.readline().strip()
    stdout.write(f"{solve(string)}\n")
