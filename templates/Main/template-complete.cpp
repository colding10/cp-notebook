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
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};
const char dir[4] {'D', 'R', 'U', 'L'}, cdir[4] {'S', 'E', 'N', 'W'};

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

inline namespace ReadIO {
template <class A, class B> void re(P<A, B> &p);
template <class A> void re(V<A> &v);
template <class A, size_t SZ> void re(AR<A, SZ> &a);

template <class T> void re(T &x) {
    cin >> x;
}
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
template <class A, class B> void re(P<A, B> &p) {
    re(p.first, p.second);
}
template <class A> void re(V<A> &x) {
    for (auto &i : x)
        re(i);
}
template <class A, size_t SZ> void re(AR<A, SZ> &x) {
    for (auto &i : x)
        re(i);
}
}; // namespace ReadIO

namespace WriteIO {
inline namespace WriteIO_impl {
template <class T> void out_elem(T &x, const string &delimiter = " ") {
    cout << x << delimiter;
}
template <class T> void out_elem(const vector<T> &v, const string &delimiter) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0)
            cout << delimiter;
        cout << v[i];
    }
}

template <class T, size_t SZ>
void out_elem(const array<T, SZ> &a, const string &delimiter) {
    for (size_t i = 0; i < SZ; ++i) {
        if (i > 0)
            cout << delimiter;
        cout << a[i];
    }
}

} // namespace WriteIO_impl

template <class T> void out(T &x, const str &delimiter = "\n") {
    WriteIO_impl::out_elem(x, delimiter);
}

void out(double &d, int pres = 5, const str &end = "\n") {
    cout << setprecision(pres) << d << end;
}

void out(long double &d, int pres = 5, const str &end = "\n") {
    cout << setprecision(pres) << d << end;
}

template <class H, class... T> void out(H &h, T &...t) {
    out_elem(h);
    out(t...);
}

template <class A, class B> void out(P<A, B> &p) {
    out_elem(p.first);
    out_elem(p.second);
}

template <class A> void out(V<A> &x, const str &delimiter = " ") {
    out_elem(x, delimiter);
}

template <class A, size_t SZ>
void out(AR<A, SZ> &x, const str &delimiter = " ") {
    out_elem(x, delimiter);
}

} // namespace WriteIO
int main() {
    setIO();
    int n;
    re(n);
    vi a(n);
    re(a);
    cout << reduce(all(a)) << endl;
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
