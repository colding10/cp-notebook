#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bit(char c) { return c - '0'; }

void solve() {
    int N, K;
    cin >> N >> K;
    string r;
    cin >> r;

    int M = N - K + 1;

    if (M == 1) {
        // only 1 window so xor all bits = r1
        int p = bit(r[0]);
        ll _min = (p == 0 ? 0 : 1);
        ll _max = ((N % 2) == p ? N : N - 1);
        cout << _min << " " << _max << "\n";
        return;
    }

    vector<int> d(N + 1);
    // d[i] = b_i xor b_{i + k}
    for (int i = 1; i <= N - K; i++) {
        d[i] = bit(r[i]) ^ bit(r[i - 1]);
    }

    int need_parity = bit(r[0]);
    ll min_ones = 0, max_ones = 0;
    int min_parity = 0, max_parity = 0;
    ll best_penalty = LLONG_MAX;

    // sometimes after optimizing chains there is gna be parity mismatch with r1
    // so u need to flip a chain
    // we store the least penalty one in best_penalty

    for (int chain_start = 1; chain_start <= K; chain_start++) {
        int cur = 0;
        ll chain_len = 0;
        ll c = 0;

        for (int i = chain_start; i <= N; i += K) {
            chain_len++;
            c += cur;
            if (i + K <= N) {
                cur ^= d[i];
            }
        }

        ll A = c;
        ll B = chain_len - c;
        ll chain_penalty = llabs(A - B);
        best_penalty = min(best_penalty, chain_penalty);

        if (B < A) {
            min_ones += B;
            min_parity ^= 1;
        } else {
            min_ones += A;
        }

        if (B > A) {
            max_ones += B;
            max_parity ^= 1;
        } else {
            max_ones += A;
        }
    }

    if (min_parity != need_parity) {
        min_ones += best_penalty;
    }
    if (max_parity != need_parity) {
        max_ones -= best_penalty;
    }

    cout << min_ones << " " << max_ones << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
