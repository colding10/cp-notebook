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

int main() {
    setIO("rental");
    int n, m, r;
    cin >> n >> m >> r;

    vi milk(n);
    rep(i, 0, n) {
        cin >> milk[i];
    }
    vpi store(m);
    rep(i, 0, m) {
        cin >> store[i].se >> store[i].fi;
    }

    vi rent(r);
    rep(i, 0, r) {
        cin >> rent[i];
    }

    sort(begin(milk), end(milk), greater<int>());
    sort(begin(store), end(store), greater<pi>());
    sort(begin(rent), end(rent), greater<int>());

    int shop_i = 0;
    int rent_i = 0;
    int cow_i = 0;

    ll ans = 0;

    while (cow_i < n) {
        int prod = milk[cow_i];
        
        int sell_money = 0;
        int curr_shop = shop_i;
        int last = 0;

        while (curr_shop < m) {
            int sold_amt = min(prod, store[curr_shop].se);
            sell_money += store[curr_shop].fi * sold_amt;

            prod -= sold_amt;
            
            if (prod == 0) {
                last = sold_amt;
                break;
            } else {
                curr_shop++;
            }
        }

        if (rent_i >= r || sell_money > rent[rent_i]) {
            ans += sell_money;
            shop_i = curr_shop;
            if (shop_i < m) {
                store[shop_i].se -= last; // decrease their willingness to buy
            }
            cow_i++;
        } else {
            ans += rent[rent_i];
            n--;
            rent_i++;
        }
    }
    cout << ans << endl;

    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
