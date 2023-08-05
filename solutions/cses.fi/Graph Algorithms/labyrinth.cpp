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
const char dir[4]{'D', 'R', 'U', 'L'};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

char graph[1005][1005];
bool visited[1005][1005];
int prev_step[1005][1005];

int n, m;

void bfs(int sx, int sy, int tx, int ty) {
    queue<pi> q;

    visited[sx][sy] = true;

    q.push({sx, sy});

    while (!q.empty()) {
        auto v = q.front();

        q.pop();

        if (v.f == tx && v.s == ty) {
            return;
        }

        F0R(i, 4) {
            int nx = v.f + dx[i];
            int ny = v.s + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (visited[nx][ny] || graph[nx][ny] == '#') continue;

            visited[nx][ny] = true;
            prev_step[nx][ny] = i;

            q.push({nx, ny});
        }
    }
}

int main() {
    setIO();

    cin >> n >> m;

    pi begin;
    pi end;

    char c;
    F0R(i, n) {
        F0R(j, m) {
            cin >> c;
            assert(c == '#' || c == '.' || c == 'A' || c == 'B');

            if (c == 'A') {
                begin = mp(i, j);
            } else if (c == 'B') {
                end = mp(i, j);
            }

            graph[i][j] = c;
        }
    }

    bfs(begin.f, begin.s, end.f, end.s);

    if (visited[end.f][end.s]) {
        cout << "YES" << endl;
        vi steps;
        while (begin != end) {
            int p = prev_step[end.f][end.s];
            steps.pb(p);

            end = mp(end.f - dx[p], end.s - dy[p]);
        }

        reverse(steps.begin(), steps.end());

        cout << sz(steps) << endl;
        for (char c : steps) {
            cout << dir[c];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
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
