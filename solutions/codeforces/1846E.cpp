#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll, ll>;
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

ll n;

bool verify(ll k) {
    ll s = 0;
    ll exp = 0;

    while (s <= n) {
        ll term = pow(k, exp);
        s += term;
        if (s == n && exp > 1) {
            return true;
        }
        exp++;
    }
    return false;
}

void solve() {
    cin >> n;
    for (ll k = 2; k <= sqrt(n); k++) {
        if (verify(k)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
