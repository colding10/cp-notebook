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
    vll a(n + 1, 0);
    vll mx(n + 1, 0);

    rep(n) {
        int x;
        cin >> x;
        if (x <= n) a[x]++;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i)
            mx[j] += a[i];
    }

    cout << *max_element(begin(mx), end(mx)) << endl;
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
