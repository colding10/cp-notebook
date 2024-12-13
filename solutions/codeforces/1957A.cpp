#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> counts(101);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        ans += (counts[i] / 3);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}