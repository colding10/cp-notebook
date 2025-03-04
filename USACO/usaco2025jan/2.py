def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])  # Number of test cases
    idx = 1
    results = []
    
    for _ in range(T):
        N, M = map(int, data[idx:idx+2])
        idx += 2
        a = list(map(int, data[idx:idx+N]))
        idx += N
        
        # Compute residues modulo M
        residues = [x % M for x in a]
        
        # Count frequency of each residue
        from collections import Counter
        freq = Counter(residues)
        
        # Sort unique residues
        unique_residues = sorted(freq.keys())
        prefix_sum = [0] * len(unique_residues)
        total_count = 0
        
        # Compute prefix sums for fast alignment cost calculation
        for i, r in enumerate(unique_residues):
            total_count += freq[r]
            prefix_sum[i] = total_count
        
        # Minimize operations
        min_cost = float('inf')
        for i, target_r in enumerate(unique_residues):
            cost = 0
            
            # Calculate cost to align all residues to target_r
            for r, count in freq.items():
                diff = abs(r - target_r)
                cost += min(diff, M - diff) * count
            
            min_cost = min(min_cost, cost)
        
        results.append(min_cost)
    
    # Print all results
    sys.stdout.write("\n".join(map(str, results)) + "\n")

solve()
