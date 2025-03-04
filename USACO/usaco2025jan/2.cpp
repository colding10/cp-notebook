#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T; // Number of test cases
    cin >> T;
    while (T--) {
        long long N, M; // Size of array and modulo value
        cin >> N >> M;
        vector<long long> a(N);

        // Read the array
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        // Frequency map for residues modulo M
        vector<long long> freq(M, 0);
        for (int i = 0; i < N; i++) {
            freq[a[i] % M]++;
        }

        // Calculate the minimal cost
        long long min_cost = LLONG_MAX;

        // Iterate over all possible residues x % M
        for (long long x = 0; x < M; x++) {
            long long cost = 0;
            for (long long r = 0; r < M; r++) {
                long long delta = abs(x - r); // Distance between residues
                delta = min(delta, M - delta); // Circular distance modulo M
                cost += delta * freq[r]; // Multiply by frequency of residue
            }
            min_cost = min(min_cost, cost); // Track minimum cost
        }

        // Output the minimum cost
        cout << min_cost << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
