#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> lc(n + 1), rc(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> lc[i] >> rc[i];
        }

        vector<int> order;
        order.reserve(n);
        stack<int> stk;
        stk.push(1);
        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();
            order.push_back(v);
            if (lc[v]) {
                stk.push(lc[v]);
                stk.push(rc[v]);
            }
        }
        reverse(order.begin(), order.end());

        vector<long long> f(n + 1);
        for (int v : order) {
            if (!lc[v]) {
                f[v] = 1;
            } else {
                f[v] = (f[lc[v]] + f[rc[v]] + 3) % MOD;
            }
        }

        vector<long long> S(n + 1);
        S[1] = f[1];
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int v = order[i];
            if (lc[v]) {
                S[lc[v]] = (f[lc[v]] + S[v]) % MOD;
                S[rc[v]] = (f[rc[v]] + S[v]) % MOD;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << S[i];
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
