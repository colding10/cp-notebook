#include <bits/stdc++.h>
#include <thread>
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
    if (sz(s)) {
        setIn(s + ".in"), setOut(s + ".out");
    }
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

int n, m;
V<char> type;
V<vi> adj;

vi cpn_id;
int id = 1;

void dfs(int v, int p = -1) {
    if (v != 0) {
        if (type[v] == type[p]) {
            cpn_id[v] = cpn_id[p];
        } else {
            cpn_id[v] = id;
            id++;
        }
    } else {
        cpn_id[0] = 0;
    }
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int main() {
    setIO("milkvisits");
    cin >> n >> m;
    type.rsz(n);
    adj.rsz(n);
    cpn_id.rsz(n);
    rep(i, 0, n) {
        cin >> type[i];
    }

    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0);
    rep(i, 0, m) {
        int a, b;
        char t;
        cin >> a >> b >> t;
        a--, b--;

        if (cpn_id[a] == cpn_id[b]) {
            cout << (t == type[a]);
        } else {
            cout << 1;
        }
    }
    cout << endl;
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
