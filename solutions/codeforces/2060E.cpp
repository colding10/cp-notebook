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


struct DisjointSets {
	int n, connected_comps;
	vector<int> parents, sizes;

	DisjointSets(int n) : n(n), connected_comps(n) {
		parents = vector<int>(n);
		iota(begin(parents), end(parents), 0);
		sizes = vector<int>(n, 1);
	}

	int get(int x) {
		if (x == parents[x]) { return x; }
		return parents[x] = get(parents[x]);
	}

	bool unite(int x, int y) {
		int x_root = get(x);
		int y_root = get(y);

		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { std::swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		connected_comps--;

		return true;
	}

	bool connected(int x, int y) { return (get(x) == get(y)); }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DisjointSets g(n);
    DisjointSets f(n);

    vpi f_edges(m1);
    rep(i, 0, m1) {
        int a, b;
        cin >> a >> b;
        f_edges[i] = mp(a-1, b-1);
    }

    rep(i, 0, m2) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.unite(a, b);
    }

    int ans = 0;
    rep(i, 0, m1) {
        if (g.connected(f_edges[i].fi, f_edges[i].se)) {
            f.unite(f_edges[i].fi, f_edges[i].se);
        } else {
            ans++;
        }
    }

    ans += f.connected_comps - g.connected_comps;
    cout << ans << endl;
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
