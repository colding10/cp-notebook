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

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
using namespace std;

const int MAX_N = 1000;
const int DIRS = 4;
const int INF = 1e9;

// Directions: L, R, U, D
int dx[DIRS] = {0, 0, -1, 1};
int dy[DIRS] = {-1, 1, 0, 0};
char belt[DIRS] = {'L', 'R', 'U', 'D'};

int N, Q;
vector<vector<char>> grid;
vector<vector<bool>> visited;

// Convert direction character to index
int dirIndex(char c) {
    for (int i = 0; i < DIRS; i++) {
        if (belt[i] == c) return i;
    }
    return -1;
}

// BFS to find unusable cells
int countUnusable() {
    visited.assign(N, vector<bool>(N, false));
    int unusable = 0;

    set<pair<int, int>> bustedpath;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || grid[i][j] == '?') continue;
            vector<pair<int, int>> path;

            // Track the cycle or exit
            int x = i, y = j;

            while (true) {
                if (x < 0 || x >= N || y < 0 || y >= N) break; // Exits grid

                if (find(begin(path), end(path), mp(x, y)) != end(path) || bustedpath.count(mp(x, y))) {
                    dbg(path);
                    for (auto& x : path) {
                        bustedpath.insert(x);
                    }
                    break; // Cycle found
                }
                if (visited[x][y]) break;
                visited[x][y] = true;

                path.emplace_back(x, y);

                if (grid[x][y] == '?') {
                    break;
                }
                int d = dirIndex(grid[x][y]);
                x += dx[d];
                y += dy[d];
            }
        }
    }
        for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || grid[i][j] != '?') continue;
            vector<pair<int, int>> path;

            int x = i, y = j;

            while (true) {
                if (x < 0 || x >= N || y < 0 || y >= N) break; // Exits grid
                bool bad = True;
                rep(d, 0, 4) {
                    x = i + dx[d];
                    y = j + dy[d];
                    
                    set<char> good_dirs = {'R', 'L', 'U', 'D'};

                    if (!bustedpath.count(mp(x, y)) || dirIndex(grid[x][y]) ) {
                         
                    }
                }
                if (find(begin(path), end(path), mp(x, y)) != end(path) || bustedpath.count(mp(x, y))) {
                    dbg(path);
                    for (auto& x : path) {
                        bustedpath.insert(x);
                    }
                    break; // Cycle found
                }
                if (visited[x][y]) break;
                visited[x][y] = true;

                path.emplace_back(x, y);

                if (grid[x][y] == '?') {
                    break;
                }
                
            }
        }
    }

    return sz(bustedpath);
}

int main() {
    cin >> N >> Q;
    grid.assign(N, vector<char>(N, '?'));

    for (int q = 0; q < Q; q++) {
        int r, c;
        char t;
        cin >> r >> c >> t;
        r--, c--;

        grid[r][c] = t;

        // Recalculate unusable cells
        cout << countUnusable() << endl;
    }

    return 0;
}
