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
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) { cin >> a[i]; }

    sort(a.begin(), a.end());
    multiset<int> lines;

    F0R(i, n) {
        int x = a[i];
        if (lines.count(x - 1)) {
            lines.erase(lines.find(x - 1));
            lines.insert(x);
            continue;
        }
        if (x == 0) {
            lines.insert(x);
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
