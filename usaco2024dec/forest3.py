def max_trees_cut(T, test_cases):
    from bisect import bisect_left, bisect_right
    results = []

    for t in range(T):
        N, K = test_cases[t][0]
        positions = test_cases[t][1]
        restrictions = test_cases[t][2]

        # Sort positions for easy handling
        sorted_positions = sorted(positions)

        # Set to track globally required trees
        global_to_keep = set()

        # Process each restriction
        for l, r, ti in restrictions:
            # Get trees within the range [l, r]
            left_idx = bisect_left(sorted_positions, l)
            right_idx = bisect_right(sorted_positions, r)

            # Trees in the current range
            range_trees = sorted_positions[left_idx:right_idx]

            # Already marked trees in this range
            already_marked = sum(1 for tree in range_trees if tree in global_to_keep)

            # Mark additional trees to satisfy this restriction
            for tree in range_trees:
                if already_marked >= ti:
                    break
                if tree not in global_to_keep:
                    global_to_keep.add(tree)
                    already_marked += 1

        # Calculate results
        trees_kept = len(global_to_keep)
        max_cut = N - trees_kept
        results.append(max_cut)

    return results


# Input reading
import sys
input = sys.stdin.read
data = input().split()

T = int(data[0])
test_cases = []
idx = 1

for _ in range(T):
    N, K = map(int, data[idx:idx+2])
    idx += 2
    positions = list(map(int, data[idx:idx+N]))
    idx += N
    restrictions = []
    for __ in range(K):
        l, r, ti = map(int, data[idx:idx+3])
        restrictions.append((l, r, ti))
        idx += 3
    test_cases.append(((N, K), positions, restrictions))

# Solve and output
results = max_trees_cut(T, test_cases)
print("\n".join(map(str, results)))