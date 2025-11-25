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
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

template <class T> bool ckmin(T &a, T &b) {
    bool B = a > b;
    a = min(a, b);
    return B;
}
template <class T> bool ckmax(T &a, T &b) {
    bool B = a < b;
    a = max(a, b);
    return B;
}

template <typename T> T floor_div(T a, long long b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    return (a < 0 ? a - (b - 1) : a) / b;
}

template <typename T> T ceil_div(T a, long long b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    return (a >= 0 ? a + (b - 1) : a) / b;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        ll a, b;
        cin >> a >> b;

        ll ans = a + b;

        FOR(k, 1, 100000) {
            ll res = ceil_div(a, k) + ceil_div(b, k) + (k - 1);
            ckmin(ans, res);
        }
        cout << ans << endl;
    }
}
