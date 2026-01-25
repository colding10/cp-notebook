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
#include <unordered_set>
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
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

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
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

#define MAXN 105

struct Road {
    int fromX;
    int fromY;

    int toX;
    int toY;

    Road(int a, int b, int x, int y) : fromX(a), fromY(b), toX(x), toY(y) {}
};

inline bool operator<(const Road &l, const Road &r) {
    return tie(l.toX, l.toY, l.fromX, l.fromY) <
           tie(r.toX, r.toY, r.fromX, r.fromY);
}

int grid_size;
int cow_count;
int road_count;

bool has_cow[MAXN][MAXN] = {{}};
bool visited[MAXN][MAXN] = {{}};
set<Road> roads;

int cows_can_visit(int x, int y) {
    if (x < 0 || y < 0 || x >= grid_size || y >= grid_size) {
        return 0;
    }

    if (visited[x][y]) {
        return 0;
    }

    visited[x][y] = true;
    int i;
    int out = has_cow[x][y];
    F0R(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (roads.count(Road(x, y, nx, ny))) {
            continue; // road in the way
        }

        out += cows_can_visit(nx, ny);
    }

    return out;
}

int main() {
    setIO("countcross");
    cin >> grid_size >> cow_count >> road_count;

    int a, b, c, d;
    rep(road_count) {
        cin >> a >> b >> c >> d;
        roads.insert(Road(--a, --b, --c, --d));
        roads.insert(Road(c, d, a, b));
    }

    rep(cow_count) {
        cin >> a >> b;
        has_cow[a - 1][b - 1] = true;
    }

    vector<int> ccs;
    int i, j;
    F0R(i, grid_size) {
        F0R(j, grid_size) {
            if (!visited[i][j]) {
                int cc_size = cows_can_visit(i, j);
                if (cc_size != 0) {
                    ccs.push_back(cc_size);
                }
            }
        }
    }

    int out;
    F0R(i, sz(ccs)) {
        for (int j = i + 1; j < sz(ccs); j++) {
            out += ccs[i] * ccs[j];
        }
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
