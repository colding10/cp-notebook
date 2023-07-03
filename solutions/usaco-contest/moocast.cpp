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
#include <tuple>
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

struct Cow {
    int x;
    int y;
    int power;

    Cow(int a, int b, int p) : x(a), y(b), power(p) {}
    Cow() = default;
};

inline bool operator<(const Cow &l, const Cow &r) {
    return tie(l.x, l.y, l.power) < tie(r.x, r.y, r.power);
}

#define MAXN 205

vector<Cow> cows;
vector<bool> visited(MAXN);
bool connected[MAXN][MAXN] = {{}};

int N;

int count_visitable(int cow_idx) {
    if (visited[cow_idx])
        return 0;

    visited[cow_idx] = true;
    int out = 1;
    F0R(i, N) {
        if (connected[cow_idx][i]) {
            out += count_visitable(i);
        }
    }

    return out;
}

int main() {
    setIO("moocast");
    cin >> N;

    int x, y, power;
    rep(N) {
        cin >> x >> y >> power;
        cows.pb(Cow(x, y, power));
    }

    int i, j;
    Cow a, b;
    F0R(i, N) {
        F0R(j, N) {
            a = cows[i];
            b = cows[j];

            int delta_x = a.x - b.x;
            int delta_y = a.y - b.y;

            if ((delta_y * delta_y + delta_x * delta_x) <= a.power * a.power) {
                connected[i][j] = true;
            }
        }
    }

    int out = -1;
    F0R(i, N) {
        visited.assign(MAXN, false);
        out = max(out, count_visitable(i));
    }

    cout << out << endl;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
