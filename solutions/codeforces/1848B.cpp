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

int n, k;
vi a;

bool works(ll step) {
    int i = -1;
    map<int, int> stepped;

    while ((i + step) < n) {
        i += (step);
        if (i >= n) {
            return true;
        }
        if (stepped.size() > 2) {
            return false;
        }
        stepped[a[i]] += 1;
    }
    if (stepped.size() > 2) {
        return false;
    }
    if (stepped.size() == 1) {
        return true;
    }
    // cout << "ueu: " << step << endl;
    // cout << "ueu: (" << stepped.begin()->f << ", " << stepped.begin()->s << ")
    // ("
    //      << stepped.end()->f << ", " << stepped.end()->s << ")" << endl;
    return stepped.begin()->s <= 1 || stepped.end()->s <= 1;
}

void solve() {
    cin >> n >> k;
    a.resize(n);

    F0R(i, n) {
        cin >> a[i];
    }

    ll lo = 1;
    ll hi = n;
    ll res = -1;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (works(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << res - 1 << endl;
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
