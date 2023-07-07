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
    double n, l, h;
    cin >> n >> l >> h;

    double prev_height = numeric_limits<double>::min();
    double ans = 0.0f;

    F0R(i, n) {
        double height;
        cin >> height;

        if (i && height < (prev_height + h)) {
            double current = l * h / 2.0f;
            double overlap = (prev_height + h) - height;
            double x = (l * overlap) / (2.0f * h);
            ans += current - (x * overlap);
        } else {
            ans += l * h / 2.0f;
        }
        prev_height = height;
    }

    cout << std::setprecision(15) << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
