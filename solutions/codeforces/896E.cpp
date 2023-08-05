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

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")

int a[101010];
int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }
    while (m--) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        --l;
        auto ap = a + l;
        r -= l;
        if (t == 1) {
            while (r % 4) {
                --r;
                ap[r] -= ap[r] > x ? x : 0;
            }
            r /= 4;
            while (r--) {
                ap[0] -= ap[0] > x ? x : 0;
                ap[1] -= ap[1] > x ? x : 0;
                ap[2] -= ap[2] > x ? x : 0;
                ap[3] -= ap[3] > x ? x : 0;
                ap += 4;
            }
        } else {
            int ans = 0;
            while (r % 4) {
                --r;
                ans += ap[r] == x;
            }
            r /= 4;
            while (r--) {
                ans +=
                    (ap[0] == x) + (ap[1] == x) + (ap[2] == x) + (ap[3] == x);
                ap += 4;
            }
            cout << ans << endl;
        }
    }
    return 0;
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
