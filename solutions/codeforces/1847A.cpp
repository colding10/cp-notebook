#include <bits/stdc++.h>
#include <ostream>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<pi> diff;

    ll ans = 0;
    F0R(i, n) {
        int x;
        cin >> x;
        a[i] = x;
        if (i) {
            ll r = abs(a[i] - a[i - 1]);
            ans += r;
            diff.pb({r, i});
        }
    }

    sort(diff.rbegin(), diff.rend());

    F0R(i, k - 1) {
        pi val = diff[i];
        ans -= abs(a[val.s] - a[val.s - 1]);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
