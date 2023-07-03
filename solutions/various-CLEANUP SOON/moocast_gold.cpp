#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

//
// Basic Types
//
using ll = long long;
using db = long double;
using str = string;

//
// Pairs
//
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

#define mp make_pair
#define f first
#define s second

//
// Template for types
//
#define tcT template <class T
#define tcTU tcT, class U

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;

//
// Vector Macros
//
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

//
// Vectors
//
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
tcT > int lwb(V<T> &a, const T &b) {
    return int(lb(all(a), b) - bg(a));
}
tcT > int upb(V<T> &a, const T &b) {
    return int(ub(all(a), b) - bg(a));
}

//
// Loops
//
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

//
// Consts
//

const int MOD = (int)1e9 + 7; // 998244353;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

inline namespace FileIO {
void setIn(const str &s) {
    freopen(s.c_str(), "r", stdin);
}
void setOut(const str &s) {
    freopen(s.c_str(), "w", stdout);
}
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s))
        setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

ll N;
vector<pi> cows;
vector<bool> visited;

bool can_hit(ll power, int a, int b) {
    int x = cows[a].f - cows[b].f;
    int y = cows[a].s - cows[b].s;

    return power >= ((x * x) + (y * y));
}

ll visitable(ll power, int i) {
    if (visited[i])
        return 0;
    visited[i] = true;

    ll out = 1;
    F0R(j, N) {
        if (j == i)
            continue;
        if (can_hit(power, i, j)) {
            out += visitable(power, j);
        }
    }

    return out;
}

int main() {
    setIO("moocast");

    cin >> N;
    cows.rsz(N);
    visited.rsz(N);
    for (auto &x : cows) {
        cin >> x.f >> x.s;
    }

    ll res = 0;
    ll hi = BIG;
    ll lo = 0;
    /* while (lo <= hi) { */
    visited.assign(N, false);
    ll mid = (lo + hi) / 2;
    if (visitable(mid, 0) == N) {
        res = mid;
        hi = mid - 1;
    } else {
        lo = mid + 1;
    }
    cout << res << endl;
    // you should actually read the stuff at the bottom    }

    /* stuff you should look for
     * int overflow, array bounds
     * special cases (n=1?)
     * do smth instead of nothing and stay organized
     * WRITE STUFF DOWN
     * DON'T GET STUCK ON ONE APPROACH
     */
}
