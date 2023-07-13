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

template <class T> bool ckmin(T &a, T &b) {
    bool B = a > b;
    a = std::min(a, b);
    return B;
}
template <class T> bool ckmax(T &a, T &b) {
    bool B = a < b;
    a = std::max(a, b);
    return B;
}
void solve() {
    int n;
    cin >> n;
    int max_n = INT_MIN;
    int min_n = INT_MAX;
    rep(n) {
        int x;
        cin >> x;

        ckmax(max_n, x);
        ckmin(min_n, x);
    }

    if (min_n < 0) {
        cout << min_n << endl;
    } else {
        cout << max_n << endl;
    }
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
