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

ll psum[1500][1500] = {};
ll ans[2000007] = {};

void solve() {
    int x;
    cin >> x;
    cout << ans[x] << endl;
}

int main() {
    ll cur = 1;

    for (int i = 1; i < 1500; i++) {
        for (int j = i - 1; j >= 1; j--) {
            psum[j][i - j] = psum[j - 1][i - j] + psum[j][i - j - 1] -
                             psum[j - 1][i - j - 1] + cur * cur;
            ans[cur] = psum[j][i - j];
            cur++;
        }
    }
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
