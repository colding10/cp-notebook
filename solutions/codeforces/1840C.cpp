#include <bits/stdc++.h>
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
    ll n, k, q;
    cin >> n >> k >> q;

    ll seg_len = 0;
    ll ans = 0;

    F0R(i, n) {
        ll x;
        cin >> x;

        if (x <= q) {
            seg_len++;
        } else {
            if (seg_len >= k) {
                ans += (seg_len - k + 1) * (seg_len - k + 2) / 2;
            }
            seg_len = 0;
        }
    }
    if (seg_len >= k) {
        ans += (seg_len - k + 1) * (seg_len - k + 2) / 2;
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

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
