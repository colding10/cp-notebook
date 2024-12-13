#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, c;
    cin >> n >> q >> c;

    vector<int> ci(n);
    vector<int> maxupto(n);
    for (int i = 0; i < n; i++) {
        cin >> ci[i];
        if (i == 0) {
            maxupto[i] = ci[i];
        } else {
            maxupto[i] = max(maxupto[i-1], ci[i]);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        // cant change beginning and already is one bigger
        if (ci[a] && maxupto[b-1] > ci[a]) { // impossible
            cout << -1 << endl;
            return; 
        }

        if (!ci[b]) {
            ci[b] = ci[a]+1;
            maxupto[b] = max(maxupto[b-1], maxupto[b]);
        }

    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
