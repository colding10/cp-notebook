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

void solve() {
    int n, ans = 0, sum = numeric_limits<int>::max();
    cin >> n;
    for (int i = 0, ai; i < n; i += 1) {
        cin >> ai;
        sum &= ai;
        if (sum == 0) {
            ans += 1;
            sum = numeric_limits<int>::max();
        }
    }
    cout << max(ans, 1) << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
