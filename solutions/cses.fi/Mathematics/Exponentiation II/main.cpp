#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

int power(ll base, ll e, ll M = MOD) {
    ll result = 1;
    base %= M;
    while (e) {
        if (e & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll exp = power(b, c, MOD - 1);
    ll ans = power(a, exp, MOD);

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
