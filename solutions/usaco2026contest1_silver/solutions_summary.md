# USACO Contest Solutions Summary

## Problem 1: Lineup (lineup.cpp)

### Problem
Cows are arranged in positions and undergo a rotation process over time. Answer queries:
- Type 1: Where is cow `c` at time `t`?
- Type 2: Which cow is at position `x` at time `t`?

### Key Insights

1. **Static Zone**: Cows with index `c > t/2` never participate in any rotation - they remain stationary.

2. **Epoch-Based Movement**: The rotation happens in "epochs" where the active region size is `e + 1` at epoch `e`. Each epoch, positions shift by 2 in a circular manner (mod size).

3. **Batching Optimization**: Instead of simulating each epoch individually:
   - When at position `pos`, you can skip `k = pos/2` epochs at once
   - Position decreases by 2 per epoch until it wraps around
   - This reduces O(t) simulation to roughly O(log t)

4. **Reverse Query**: `query_cow` is the inverse of `query_pos` - same logic but running time backwards (adding instead of subtracting, reversing the epoch order).

### Complexity
- O(log t) per query due to batching

---

## Problem 2: Reactor (reactor.cpp)

### Problem
- N rods with valid energy ranges `[l_i, r_i]`
- M constraints of form `a_x + a_y = z`
- Maximize the number of "active" rods (energy is integer within bounds)
- Output -1 if constraints are impossible to satisfy

### Key Insights

1. **Graph Model**: Each constraint is an edge. Connected components are independent subproblems.

2. **Linear Parameterization**: Express every rod's energy as:
   ```
   a_i = p_i * t + c_i    where p_i ∈ {-1, +1}
   ```

   Why this works:
   - Start from root with `a_root = t` (p=1, c=0)
   - Propagate via: `a_v = z - a_u = (-p_u) * t + (z - c_u)`
   - Signs alternate like 2-coloring a bipartite graph
   - One free parameter captures the single degree of freedom in a tree component

3. **Contradiction Detection**:
   - **Same sign revisit**: If `c_v ≠ new_c` → impossible
   - **Opposite sign revisit**: Fixes `t = (new_c - c_v) / (2 * p_v)`; if t was already fixed differently → impossible
   - **Self-loops**: `2 * a_u = z` requires z even, directly fixes t

4. **Two Cases After BFS**:

   **Case A - t is fixed**: Evaluate each rod and count valid ones.

   **Case B - t is free**: Convert each rod's bounds to an interval for t:
   ```
   If p = +1:  t ∈ [l - c, r - c]
   If p = -1:  t ∈ [c - r, c - l]
   ```
   Use sweep line to find t maximizing interval overlap.

### Why Linear Parameterization?
- Constraints are additive (`a_x + a_y = z`)
- Propagation is subtraction: `a_v = z - a_u`
- Subtraction preserves linearity and alternates signs
- Tree component has exactly 1 degree of freedom → 1 parameter suffices

### Complexity
- O(N + M) for BFS traversal
- O(N log N) for sweep line sorting
- Overall: O((N + M) + N log N) per test case

---

## Problem 3: Window (window.cpp)

### Problem
- Array of N bits
- M = N - K + 1 sliding windows of size K
- Each window i has required XOR parity `r_i`
- Find minimum and maximum possible number of 1s in the array

### Key Insights

1. **Difference Relation**: From consecutive windows:
   ```
   r_i     = b_i ⊕ b_{i+1} ⊕ ... ⊕ b_{i+K-1}
   r_{i+1} = b_{i+1} ⊕ b_{i+2} ⊕ ... ⊕ b_{i+K}

   r_i ⊕ r_{i+1} = b_i ⊕ b_{i+K} = d_i
   ```
   So `d[i] = r[i-1] ⊕ r[i]` tells us the XOR relationship between bits K apart.

2. **Chain Decomposition**: Positions form K independent chains:
   ```
   Chain 1: positions 1, K+1, 2K+1, ...
   Chain 2: positions 2, K+2, 2K+2, ...
   ...
   Chain K: positions K, 2K, 3K, ...
   ```
   Within each chain, once you pick the first bit, all others are determined by d[].

3. **Counting Per Chain**: For each chain starting at position `s`:
   - A = number of 1s if first bit is 0
   - B = number of 1s if first bit is 1 = chain_length - A
   - For minimum: pick min(A, B)
   - For maximum: pick max(A, B)

4. **Parity Constraint**: The XOR of all bits must equal `r[0]`. Track the parity of your greedy choices:
   ```
   min_parity = XOR of (did we pick the "1-start" option?)
   max_parity = same for max choices
   ```

5. **Fixing Parity Mismatch**: If greedy choice has wrong parity:
   - Flip one chain's choice (swap A ↔ B)
   - Cost = |A - B| (the "penalty")
   - Pre-compute minimum penalty across all chains
   - Add penalty to min, subtract from max

### Edge Case
When M = 1 (only one window covering entire array):
- XOR of all N bits = r[0]
- Min 1s: 0 if r[0]=0, else 1
- Max 1s: N if N mod 2 = r[0], else N-1

### Complexity
- O(N) to compute d[] array
- O(N) to process all chains (each position visited once)
- Overall: O(N) per test case

---

## Summary Table

| Problem | Core Technique | Key Insight | Complexity |
|---------|---------------|-------------|------------|
| Lineup | Simulation with batching | Skip epochs in bulk when position allows | O(log t) per query |
| Reactor | Graph + linear parameterization + sweep line | One degree of freedom → one parameter t | O((N+M) + N log N) |
| Window | Chain decomposition + greedy + parity fix | Bits K apart are linked; K independent chains | O(N) |
