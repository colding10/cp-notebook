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
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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
    rep(i, 0, sz(x)) re(x[i]);
}
template <class A, size_t SZ> void re(AR<A, SZ> &x) {
    rep(i, 0, SZ) re(x[i]);
}
#define ints(...)                                                              \
  int __VA_ARGS__;                                                             \
  re(__VA_ARGS__);
}; // namespace ReadIO

inline namespace WriteIO {
template <class A, class B> void out(P<A, B> &p);
template <class A> void out(V<A> &v);
template <class A, size_t S> void out(AR<A, S> &a);

template <class T> void out(T &x) {
    cout << x;
}
template <class H, class... T> void out(H &h, T &...t) {
    out(h);
    out(t...);
}
template <class A, class B> void out(P<A, B> &p) {
    out(p.first, " ", p.second);
}
template <class A> void out(V<A> &x) {
    rep(i, 0, sz(x)) out(x[i], " \n"[x == sz(x) - 1]);
}
template <class A, size_t SZ> void out(AR<A, SZ> &x) {
    rep(i, 0, SZ) out(x[i], " \n"[x == SZ - 1]);
}
}; // namespace WriteIO

void solve() {
    ints(n);
    vi a(n);
    bool neg = false;
    bool pos = false;
    multiset<int> vals;
    int biggest = -30;
    int biggest_loc = 0;

    int smallest = 30;
    int smallest_loc = 0;
    rep(i, 0, n) {
        cin >> a[i];
        vals.insert(a[i]);
        if (a[i] > biggest) {
            biggest = a[i];
            biggest_loc = i;
        }
        if (a[i] < smallest) {
            smallest = a[i];
            smallest_loc = i;
        }
        if (a[i] < 0) {
            neg = true;
        }
        if (a[i] > 0) {
            pos = true;
        }
    }

    int ops = 0;
    vpi op_info;

    if (!pos) {
        rep(i, 1, n) {
            if (a[i] < a[i - 1]) {
                while (a[i] < a[i - 1]) {
                    ops++;
                    a[i] += smallest;
                    op_info.pb(mp(i, smallest));
                }
            }
        }

    } else {
        rep(i, 1, n) {
            if (a[i] < a[i - 1]) {
                while (a[i] < a[i - 1]) {
                    ops++;

                    int best_val = 100;
                    int best_loc = 0;
                    rep(j, 0, n) {
                        if (a[j] + a[i] - a[i - 1] < best_val && a[j] + a[i] >= a[i - 1]) {
                            best_val = a[j] + a[i] - a[i - 1];
                            best_loc = j;
                        }
                    }
                    a[i] = a[i - 1] + best_val;
                    op_info.pb(mp(i, best_loc));
                }
            }
        }
    }

    cout << ops << endl;
    rep(i, 0, ops) {
        cout << op_info[i].fi + 1 << " " << op_info[i].se + 1 << endl;
    }
}

int main() {
    setIO();

    ints(tc);

    while (tc--) {
        solve();
    }
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
