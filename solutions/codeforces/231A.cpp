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

int main() {
    int n;
    cin >> n;
    int ans = 0;
    rep(n) {
        int t = 0;
        rep(3) {
            int a;
            cin >> a;
            t += a;
        }

        ans += (t >= 2);
    }

    cout << ans << endl;
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
