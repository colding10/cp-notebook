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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

void solve() {
    ll n, c;
    cin >> n >> c;
    vi a(n);
    F0R(i, n) {
        cin >> a[i];
    }

    ll l = 1;
    ll r = 1e9;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll sumall = 0;
        F0R(i, n) {
            sumall += (a[i] + 2 * mid) * (a[i] + 2 * mid);
            if (sumall > c)
                break;
        }
        if (sumall == c) {
            cout << mid << "\n";
            return;
        }
        if (sumall > c) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
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
