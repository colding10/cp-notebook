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


int n, q;
V<V<char>> grid;
V<vi> ff_id;
V<vb> visited;

pair<char, char> edge_direction(int x, int y) {
    if (x == 0) {
        if (y == 0) {
            return mp('U', 'L');
        } else if (y == n-1) {
            return mp('U', 'R');
        } else {
            return mp('U', 'U');
        }
    } else if (x == n-1) {
        if (y == 0) {
            return mp('D', 'L');
        } else if (y == n-1) {
            return mp('D', 'R');
        } else {
            return mp('D', 'D');
        }
    } else if (y == 0) {
        return mp('L', 'L');
    } else if (y == n-1) {
        return mp('R', 'R');
    }
    return mp('.', '.');
}


void floodfill(int x, int y, int set_to) {
    if (ff_id[x][y] == set_to) {
        return;
    }


}
int main() {
    setIO();
    cin >> n >> q;
    grid.rsz(n);
    ff_id.rsz(n);
    visited.rsz(n);
    rep(i, 0, n) {
        grid[i].rsz(n);
        ff_id[i].rsz(n);
        visited[i].rsz(n);
    }

    int current_id = 69;
    rep(i, 0, q) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--, y--;
        
        pair<char, char> edge = edge_direction(x, y);
        if (!edge.fi == '.') {
            if (c == edge.fi || c == edge.se) { // escaping move!!
                floodfill(x, y, 0);
            } // 0 means that it is escaping!!
        }
    }
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
