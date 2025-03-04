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

struct UF {
    vector<int> e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
int edgeidG = 0;
struct Edge {
    int u, v, w;
    bool used = false;
    int eid;
    Edge(int U, int V, int W) : u(U), v(V), w(W) { eid = edgeidG++; }
};
V<Edge> edges;
int n, d;
UF uf(n);
int cost = 0;
int lastx = -1;
V<vb> connected;

int MST_Kruskal(int x) {
    rep(i, 0, n) {
        if (i == x) continue;
        if (connected[i][x]) {
            connected[i][x] = false;
            connected[x][i] = false;

            cost -= (x + 1) | (i + 1);
        }
    }
    if (lastx != -1) {
        int bestw = INT_MAX;
        int besti = -1;
        rep(i, 0, n) {
            if (i == lastx) continue;
            int curw = (lastx + 1) | (i + 1);
            if (curw < bestw) {
                bestw = curw;
                besti = i;
            }
        }
        cost += bestw;
        connected[x][besti] = true;
        connected[besti][x] = true;
    }
    lastx = x;
    return cost;
}

int main() {
    setIO();
    cin >> n >> d;
    uf.e.rsz(n, -1);
    connected.rsz(n);
    rep(i, 0, n) {
        connected[i].rsz(n);
        rep(j, i + 1, n) {
            int w = (i + 1) | (j + 1);
            Edge e(i, j, w);
            edges.pb(e);
        }
    }
    sort(edges.begin(), edges.end(),
         [](Edge const &e, Edge const &f) { return e.w < f.w; });
    for (Edge &e : edges) {
        if (!uf.sameSet(e.u, e.v)) {
            uf.join(e.u, e.v);
            connected[e.v][e.u] = true;
            connected[e.u][e.v] = true;
            e.used = true;
            cost += e.w;
        }
    }
    rep(i, 0, d) {
        int x;
        cin >> x;
        x--;

        cout << MST_Kruskal(x) << endl;
    }
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
