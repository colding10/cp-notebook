#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Restriction {
    int l, r, t;
};

int solveTestCase(vector<int>& trees, vector<Restriction>& restrictions) {
    // Step 1: Compress positions
    vector<int> compressed = trees;
    for (const auto& res : restrictions) {
        compressed.push_back(res.l);
        compressed.push_back(res.r);
    }
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    auto getIndex = [&](int value) {
        return lower_bound(compressed.begin(), compressed.end(), value) - compressed.begin();
    };

    int m = compressed.size();

    // Step 2: Tree counts at compressed positions
    vector<int> treeCount(m, 0);
    for (int tree : trees) {
        int idx = getIndex(tree);
        treeCount[idx]++;
    }

    // Step 3: Minimum required trees per compressed segment
    vector<int> minRequired(m, 0);
    for (const auto& res : restrictions) {
        int lIdx = getIndex(res.l);
        int rIdx = getIndex(res.r);
        minRequired[lIdx] += res.t;
        if (rIdx + 1 < m) {
            minRequired[rIdx + 1] -= res.t;
        }
    }

    // Step 4: Accumulate requirements across segments
    for (int i = 1; i < m; i++) {
        minRequired[i] += minRequired[i - 1];
    }

    // Step 5: Verify feasibility and calculate maximum cuts
    int totalCuts = 0;
    for (int i = 0; i < m; i++) {
        if (treeCount[i] < minRequired[i]) {
            return -1; // Invalid case: restrictions cannot be satisfied.
        }
        int canCut = treeCount[i] - minRequired[i];
        totalCuts += canCut;
    }

    return totalCuts;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> trees(N);
        for (int i = 0; i < N; i++) {
            cin >> trees[i];
        }

        vector<Restriction> restrictions(K);
        for (int i = 0; i < K; i++) {
            cin >> restrictions[i].l >> restrictions[i].r >> restrictions[i].t;
        }

        cout << solveTestCase(trees, restrictions) << endl;
    }

    return 0;
}