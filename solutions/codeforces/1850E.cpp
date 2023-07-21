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

vll s;
ll n, c;

bool works(ll x) {
    ll sum = 0;
    F0R(i, n) {
        sum += (s[i] + (2 * x)) * (s[i] + (2 * x));
    }

    return sum == -c;
}

void solve() {
    cin >> n >> c;

    double a = 4 * n;
    double b = 0;

    s.resize(n);
    F0R(i, n) {
        ll x;
        cin >> x;
        s[i] = x;

        c -= x * x;
        b += 4 * x;
    }
    c *= -1;

    double ans = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
   cout <<  round(ans) << endl;
    return;
    ll sfa = ll(ans);

    if (works(sfa)) {
        cout << sfa << endl;
        return;
    }
    for (ll x = sfa - 5; x < sfa + 5; x++) {
        if (works(x)) {
            cout << x << endl;
            return;
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
