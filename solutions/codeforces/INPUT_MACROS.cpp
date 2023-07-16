#include <bits/stdc++.h>
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

template <class T> using V = vector<T>;
template <class T, size_t SZ> using AR = array<T, SZ>;

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

const int INF_32 = int(2147483647);
const ll INF_64 = ll(9223372036854775807);

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

inline namespace Helpers {
// is iterable
template <class T, class = void> struct is_iterable : false_type {};
template <class T>
struct is_iterable<
T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
: true_type {};
template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;

// is readable
template <class T, class = void> struct is_readable : false_type {};
template <class T>
struct is_readable<T, typename std::enable_if_t<is_same_v<
decltype(cin >> declval<T &>()), istream &>>>
: true_type {};
template <class T> constexpr bool is_readable_v = is_readable<T>::value;

// is printable
template <class T, class = void> struct is_printable : false_type {};
template <class T>
struct is_printable<T, typename std::enable_if_t<is_same_v<
decltype(cout << declval<T>()), ostream &>>>
: true_type {};
template <class T> constexpr bool is_printable_v = is_printable<T>::value;
} // namespace Helpers

inline namespace Input {
template <class T>
constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
template <class T, class... U> void re(T &t, U &...u);
template <class T, class U> void re(pair<T, U> &p); // pairs

// re: read
template <class T> typename enable_if<is_readable_v<T>, void>::type re(T &x) {
    cin >> x;
} // default
template <class T> void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
template <class T>
typename enable_if<needs_input_v<T>, void>::type
re(T &i); // ex. vectors, arrays
template <class T, class U> void re(pair<T, U> &p) {
    re(p.f, p.s);
}
template <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i) {
    each(x, i) re(x);
}
template <class T, class... U> void re(T &t, U &...u) {
    re(t);
    re(u...);
} // read multiple

// rv: resize and read vectors
void rv(size_t) {}
template <class T, class... U> void rv(size_t N, V<T> &t, U &...u);
template <class... U> void rv(size_t, size_t N2, U &...u);
template <class T, class... U> void rv(size_t N, V<T> &t, U &...u) {
    t.rsz(N);
    re(t);
    rv(N, u...);
}
template <class... U> void rv(size_t, size_t N2, U &...u) {
    rv(N2, u...);
}

// dumb shortcuts to read in ints
void decrement() {} // subtract one from each
template <class T, class... U> void decrement(T &t, U &...u) {
    --t;
    decrement(u...);
}
#define ints(...)                                                              \
  int __VA_ARGS__;                                                             \
  re(__VA_ARGS__);
#define int1(...)                                                              \
  ints(__VA_ARGS__);                                                           \
  decrement(__VA_ARGS__);
} // namespace Input

int main() {
    
}
