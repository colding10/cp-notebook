#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
#define f first
#define s second

template <class T> bool ckmin(T &a, T &b) {
    return b < a ? a = b, true : false;
}
template <class T> bool ckmax(T &a, T &b) {
    return b > a ? a = b, true : false;
}

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

#define rep(i, begin, end)                                                     \
    for (__typeof(end) i = (begin) - ((begin) > (end));                        \
         i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const char dir[4]{'D', 'R', 'U', 'L'}, cdir[4]{'S', 'E', 'N', 'W'};

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

inline namespace ReadIO {
template <class A, class B> void re(pair<A, B> &p);
template <class A> void re(vector<A> &v);
template <class A, size_t SZ> void re(array<A, SZ> &a);

template <class T> void re(T &x) { cin >> x; }
void re(double &d) {
    string t;
    re(t);
    d = stod(t);
}
void re(long double &d) {
    string t;
    re(t);
    d = stold(t);
}
template <class H, class... T> void re(H &h, T &...t) {
    re(h);
    re(t...);
}
template <class A, class B> void re(pair<A, B> &p) { re(p.first, p.second); }
template <class A> void re(vector<A> &x) {
    for (auto &i : x)
        re(i);
}
template <class A, size_t SZ> void re(array<A, SZ> &x) {
    for (auto &i : x)
        re(i);
}
}; // namespace ReadIO

struct PCL {
    PCL(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    int x1, y1, x2, y2;
};

inline namespace WriteIO {
void print(PCL &p) {
    cout << "PCL(" << p.x1 << ", " << p.y1 << ", " << p.x2 << ", " << p.y2
         << ")" << endl;
}
}; // namespace WriteIO

int N;
V<V<char>> grid;
V<PCL> pcls;
V<V<bool>> visited;

void floodfill(int i, int j, int c, int i1, int j1, int i2, int j2) {
    visited[i][j] = true;
    if (i > i1 && grid[i - 1][j] - 'A' == c && !visited[i - 1][j])
        floodfill(i - 1, j, c, i1, j1, i2, j2);
    if (i < i2 && grid[i + 1][j] - 'A' == c && !visited[i + 1][j])
        floodfill(i + 1, j, c, i1, j1, i2, j2);
    if (j > j1 && grid[i][j - 1] - 'A' == c && !visited[i][j - 1])
        floodfill(i, j - 1, c, i1, j1, i2, j2);
    if (j < j2 && grid[i][j + 1] - 'A' == c && !visited[i][j + 1])
        floodfill(i, j + 1, c, i1, j1, i2, j2);
}

bool isPCL(int i1, int j1, int i2, int j2) {
    int num_colors = 0;
    int color_count[26] = {0};
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            visited[i][j] = false;
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            if (!visited[i][j]) {
                int c = grid[i][j] - 'A';
                if (color_count[c] == 0) num_colors++;
                color_count[c]++;
                floodfill(i, j, c, i1, j1, i2, j2);
            }
    if (num_colors != 2) return false;
    bool found_one = false, found_many = false;
    for (int i = 0; i < 26; i++) {
        if (color_count[i] == 1) found_one = true;
        if (color_count[i] > 1) found_many = true;
    }
    return found_one && found_many;
}

bool withinPCL(int x, int y) {
    return pcls[x].x1 >= pcls[y].x1 && pcls[x].x2 <= pcls[y].x2 &&
           pcls[x].y1 >= pcls[y].y1 && pcls[x].y2 <= pcls[y].y2;
}

bool isMaxPCL(int x) {
    rep(i, 0, sz(pcls)) {
        if (i != x && withinPCL(x, i)) return false;
    }

    return true;
}

int main() {
    setIO("where");

    cin >> N;
    grid.rsz(N);
    visited.rsz(N);
    rep(i, 0, N) {
        grid[i].rsz(N);
        visited[i].rsz(N);
        rep(j, 0, N) {
            cin >> grid[i][j];
        }
    }

    rep(x1, 0, N) {
        rep(y1, 0, N) {
            rep(x2, x1, N) {
                rep(y2, y1, N) {
                    if (isPCL(x1, y1, x2, y2)) {
                        pcls.pb(PCL(x1, y1, x2, y2));
                    }
                }
            }
        }
    }

    int ans = 0;
    rep(i, 0, sz(pcls)) {
        if (isMaxPCL(i)) {
            // print(pcls[i]);
            ans++;
        }
    }

    cout << ans << endl;
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
