#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
using namespace std;

using ll = long long int;
using str = string;
using db = long double;

template <class T> using V = vector<T>;
template <class T, class U> using P = pair<T, U>;
template <class T, size_t SZ> using AR = array<T, SZ>;

using pi = P<int, int>;
using pll = P<ll, ll>;

using vi = V<int>;
using vll = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;
using vpll = V<pll>;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back

#define rep(i, begin, end)                                                     \
    for (__typeof(end) i = (begin) - ((begin) > (end));                        \
         i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

// bessie gets the minimal continigous subsequence prefix sum of length N - (n/2
// -1) elsie gets the rest;
void solve() {
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vll psum(n + 1);
    rep(i, 0, n) {
        psum[i + 1] = psum[i] + a[i];
    }


    ll minimal = INT64_MAX;
    ll amt_bessie = n - (n/2) + 1;
    rep(i, amt_bessie, n+1) {
        ll val = psum[i] - psum[i-amt_bessie];
        minimal = min(minimal, val);
    }

    cout << minimal << " " << psum[n]-minimal << endl;
}

int main() {
    setIO();

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
