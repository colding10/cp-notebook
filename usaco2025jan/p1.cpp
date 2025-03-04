#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Fenwick Tree class for range query and updates
class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        for (; index <= size; index += index & -index) {
            tree[index] += value;
        }
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

    int range_query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> a(N + 1), b(N + 1);

    // Read input arrays
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];

    // Map positions of each species in b
    unordered_map<int, vector<int>> b_positions;
    for (int i = 1; i <= N; ++i) {
        b_positions[b[i]].push_back(i);
    }

    long long total_checked = 0;

    // Fenwick Tree for range counting
    FenwickTree fenwick(N);

    // Iterate over all starting points l
    for (int l = 1; l <= N; ++l) {
        // Reset Fenwick Tree for this starting point
        fenwick = FenwickTree(N);

        // Add matches dynamically as r expands
        for (int r = l; r <= N; ++r) {
            // If a[r] exists in b, update its positions in the Fenwick Tree
            if (b_positions.find(a[r]) != b_positions.end()) {
                for (int pos : b_positions[a[r]]) {
                    if (pos >= l && pos <= r) {
                        fenwick.update(pos, 1);
                    }
                }
            }

            // Query the Fenwick Tree for total matches in range [l, r]
            total_checked += fenwick.range_query(l, r);
        }
    }

    cout << total_checked << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}