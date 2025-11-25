#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;

using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

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

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = (int)1e9 + 7; // 998244353;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every grid problem!!
const char dir[4]{'D', 'R', 'U', 'L'}, cdir[4]{'S', 'E', 'N', 'W'};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

int t;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES" << endl;
        cout << n << endl;
        rep(n) {
            cout << "1 ";
        }
        cout << endl;
    } else {
        if (k <= 1) {
            cout << "NO" << endl;
        } else {
            if (k == 2) { // can only use 2
                if (n % 2 == 0) {
                    cout << "YES" << endl;
                    cout << n / 2 << endl;
                    rep(n / 2) {
                        cout << "2 ";
                    }
                    cout << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else { // can use 2 + 3
                if (n % 2 == 0) {
                    cout << "YES" << endl;
                    cout << n / 2 << endl;
                    rep(n / 2) {
                        cout << "2 ";
                    }
                    cout << endl;
                } else {
                    if ((n - 3) % 2 == 0) {
                        cout << "YES" << endl;
                        cout << ((n - 3) / 2) + 1 << endl;
                        rep((n - 3) / 2) {
                            cout << "2 ";
                        }
                        cout << "3" << endl;
                    } else if ((n - 2) % 3 == 0) {
                        cout << "YES" << endl;
                        cout << ((n - 2) / 3) + 1 << endl;
                        rep((n - 2) / 3) {
                            cout << "3 ";
                        }
                        cout << "2" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
}
int main() {
    setIO();
    cin >> t;

    rep(t) {
        solve();
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
