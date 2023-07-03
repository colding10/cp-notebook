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
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = (int)1e9 + 7; // 998244353;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1}; // for every grid problem!!
const char dir[4] {'D', 'R', 'U', 'L'}, cdir[4] {'S', 'E', 'N', 'W'};
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

str database;
vector<int> l, r;
int m;
vector<int> pass;
bool found_one;

bool in_db() {
    int m_ptr = 0;
    int db_ptr = 0;

    while (db_ptr < sz(database)) {
        if (database[db_ptr] - '0' == pass[m_ptr]) {
            m_ptr++;
        }
        db_ptr++;
    }

    return m_ptr < m;
}

void recurse(int i) {
    if (found_one)
        return;

    if (i == m) {
        found_one = in_db();
        return;
    }

    for (int digit = l[i]; digit <= r[i]; digit++) {
        pass[i] = digit;
        recurse(i + 1);
    }
}
void solve() {
    found_one = false;

    cin >> database;
    cin >> m;

    l.rsz(m);
    r.rsz(m);

    F0R(i, m) {
        char c;
        cin >> c;
        l[i] = c - '0';
    }
    F0R(i, m) {
        char c;
        cin >> c;
        r[i] = c - '0';
    }

    pass.rsz(m);
    recurse(0);

    if (found_one) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void solve_greedy() {
    cin >> database;
    cin >> m;

    int n = sz(database);

    l.rsz(m);
    r.rsz(m);

    F0R(i, m) {
        char c;
        cin >> c;
        l[i] = c - '0';
    }
    F0R(i, m) {
        char c;
        cin >> c;
        r[i] = c - '0';
    }

    int db_ptr = 0;
    F0R(i, m) {
        int li = l[i];
        int ri = r[i];

        int dmx = -1;

        for (int d = li; d <= ri; d++) {
            int cur = db_ptr;

            while (cur < n && database[cur] - '0' != d) {
                cur++;
            }

            ckmax(dmx, cur);
        }

        db_ptr = dmx + 1;
    }

    cout << ((db_ptr > n) ? "YES" : "NO") << endl;
}
int main() {
    setIO();

    int t;
    cin >> t;

    rep(t) {
        solve_greedy();
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
