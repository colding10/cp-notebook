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

const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const char dir[4]{'D', 'R', 'U', 'L'}, cdir[4]{'S', 'E', 'N', 'W'};

int n;
V<vi> graph;
V<vb> visited;

int sin_best = -1;
int mul_best = -1;

int floodfill1(int i, int j, int c) {
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    
    int out = 1;
    rep(a, 0, 4) {
        int x = i + dx[a];
        int y = j + dy[a];

        if (x < 0 || x >= n || y < 0 || y >= n) continue;
        out += 
    }
}

int main() {
    setIO();
    cin >> n;
    graph.rsz(n);
    visited.rsz(n);
    rep(i, 0, n) {
        graph[i].rsz(n);
        visited[i].rsz(n);
        rep(j, 0, n) {
            cin >> graph[i][j];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (!visited[i][j]) {
                floodfill1(i, j, graph[i][j]);
            }
        }
    }

    cout << sin_best << endl;
    cout << mul_best << endl;
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
