#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx2", "popcnt")
#include <bits/stdc++.h>
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

inline namespace Debug {
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}
template <typename T> void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define dbg(x...)                                                              \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";  \
    _print(x);                                                                 \
    cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
} // namespace Debug

void solve() {
    int n, p;
    cin >> n >> p;
    V<V<int>> tubes(3);
    char prev = 'a';
    rep(i, 0, n) {
        char a;
        cin >> a;
        if (a != prev) {
            tubes[0].pb(a - '0');
            prev = a;
        }
    }
    prev = 'a';
    rep(i, 0, n) {
        char a;
        cin >> a;
        if (a != prev) {
            tubes[1].pb(a - '0');
            prev = a;
        }
    }

    if (tubes[0][0] == tubes[1][0]) {
        tubes[0].insert(begin(tubes[0]), (tubes[0][0] == 1 ? 2 : 1));
    }

    int ans = sz(tubes[0]) + sz(tubes[1]) - 2;
    if (tubes[0][0] == tubes[1][0]) {
        ans++;
    }
    if (ans > 1) {
        ans++;
    }
    cout << ans << endl;
    if (p == 1) {
        return;
    }

    V<pi> moves;
    auto move = [&](int a, int b) {
        moves.pb(mp(a, b));
        if (sz(tubes[b]) == 0 || tubes[b].back() != tubes[a].back()) {
            tubes[b].pb(tubes[a].back());
        }
        tubes[a].pop_back();
    };
    if (tubes[0].back() == tubes[1].back()) {
        if (sz(tubes[0]) > sz(tubes[1])) {
            move(0, 1);
        } else {
            move(1, 0);
        }
    }

    rep(tubeid, 0, 2) {
        if ((sz(tubes[tubeid])) > 1) {
            move(tubeid, 2); // move to beaker
            int i = 0;
            if (tubes[i][0] == tubes[2][0]) {
                i ^= 1;
            }
            while (sz(tubes[i]) > 1) {
                if (tubes[i].back() == tubes[2][0]) {
                    move(i, 2);
                } else {
                    move(i, i ^ 1);
                }
            }
            i ^= 1;
            while (sz(tubes[i]) > 1) {
                if (tubes[i].back() == tubes[2][0]) {
                    move(i, 2);
                } else {
                    move(i, i ^ 1);
                }
            }
            move(2, i);
            break;
        }
    }

    assert(sz(moves) == ans);
    for (auto p : moves) {
        int a = p.fi, b = p.se;
        cout << a + 1 << " " << b + 1 << endl;
    }
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
