#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Competitive programming style setup
#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAXN = 200005;

int N;
int b[MAXN];
int p[MAXN]; // prev_occurrence
int n[MAXN]; // next_occurrence
std::vector<int> deactivate_events[MAXN + 2];
ll bit[MAXN];

// Fenwick Tree (BIT) update operation
void update(int idx, int val) {
    for (; idx <= N; idx += idx & -idx) {
        bit[idx] += val;
    }
}

// Fenwick Tree (BIT) query operation
ll query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int main() {
    FAST_IO;

    std::cin >> N;
    rep(i, 1, N) {
        std::cin >> b[i];
    }

    // Precompute prev_occurrence[i]: index of previous cow with same breed
    std::vector<int> last_seen(N + 1, 0);
    rep(i, 1, N) {
        p[i] = last_seen[b[i]];
        last_seen[b[i]] = i;
    }

    // Precompute next_occurrence[i]: index of next cow with same breed
    std::fill(last_seen.begin(), last_seen.end(), N + 1);
    for (int i = N; i >= 1; --i) {
        n[i] = last_seen[b[i]];
        last_seen[b[i]] = i;
    }

    // For each time r, store which l's become invalid (n[l] == r)
    rep(i, 1, N) {
        deactivate_events[n[i]].push_back(i);
    }

    ll total_pairs = 0;
    
    // Sweep line from r = 1 to N
    rep(r, 1, N) {
        // Deactivate any l where n[l] == r. They are no longer valid for this r or any future r'.
        for (int l_to_deactivate : deactivate_events[r]) {
            update(l_to_deactivate, -1);
        }

        // For the current right leader r, count valid left leaders l.
        // A valid l must satisfy: prev_occurrence[r] < l < r AND next_occurrence[l] > r.
        // The BIT stores active l's (those added and not yet deactivated), fulfilling the second condition.
        // We query for active l's in the range [p[r] + 1, r - 1].
        if (p[r] < r - 1) {
            total_pairs += query(r - 1) - query(p[r]);
        }
        
        // Add r to the set of potential l's for future steps r' > r.
        // It will be active until it's deactivated at time n[r].
        update(r, 1);
    }

    std::cout << total_pairs << std::endl;

    return 0;
}

