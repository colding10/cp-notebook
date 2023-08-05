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

int N, K;
vector<array<int, 10>> graph;
vector<array<bool, 10>> s_visited;
vector<array<bool, 10>> d_visited;

void s_reset_visited() {
    int i;
    F0R(i, N) {
        int j;
        F0R(j, 10) { s_visited[i][j] = false; }
    }
}

void d_reset_visited() {
    int i;
    F0R(i, N) {
        int j;
        F0R(j, 10) { d_visited[i][j] = false; }
    }
}

void delete_cc(int i, int j, int color) {
    if (i < 0 || j < 0 || i >= N || j >= 10) {
        return;
    }
    if (d_visited[i][j]) {
        return;
    }
    if (graph[i][j] != color) {
        return;
    }
    d_visited[i][j] = true;
    graph[i][j] = 0;
    int x;
    F0R(x, 4) { delete_cc(i + dx[x], j + dy[x], color); }
}

int cc_size(int i, int j, int color) {
    if (i < 0 || j < 0 || i >= N || j >= 10) {
        return 0;
    }
    if (s_visited[i][j]) {
        return 0;
    }
    if (graph[i][j] != color) {
        return 0;
    }

    s_visited[i][j] = true;

    int out = 1;
    int x;
    F0R(x, 4) { out += cc_size(i + dx[x], j + dy[x], color); }

    return out;
}

void apply_gravity() {
    int col;
    F0R(col, 10) {
        int r;
        int open_spot = N - 1;
        R0F(r, N) {
            if (graph[r][col]) {
                graph[open_spot][col] = graph[r][col];
                if (open_spot != r) {
                    graph[r][col] = 0;
                }
                open_spot--;
            }
        }
    }
}

void print_graph() {
    int i, j;
    F0R(i, N) {
        F0R(j, 10) { cout << graph[i][j]; }
        cout << endl;
    }
}
int main() {
    setIO("mooyomooyo");
    cin >> N >> K;
    graph.rsz(N);
    s_visited.rsz(N);
    d_visited.rsz(N);

    int x, y;
    char c;

    F0R(x, N) {
        F0R(y, 10) {
            cin >> c;
            graph[x][y] = c - '0';
        }
    }
    // cout << "graph at first: " << endl;
    // cout << "cc_size(5, 7): " << cc_size(5, 7, graph[5][7]) << endl;

    while (true) {
        // cout << "looping" << endl;
        s_reset_visited();
        d_reset_visited();
        // cout << "graph before iter" << endl;
        int i, j;
        bool deleted_one = false;
        F0R(i, N) {
            F0R(j, 10) {
                if (graph[i][j] == 0) continue;

                if (cc_size(i, j, graph[i][j]) >= K) {
                    delete_cc(i, j, graph[i][j]);
                    deleted_one = true;
                }
            }
        }

        apply_gravity();
        if (!deleted_one) {
            break;
        }
    }
    print_graph();
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
