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

#define tcT template <class T
#define tcTU tcT, class U

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;

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

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
using Log = array<int, 3>;

int main() {
    setIO("measurement");
    int n, g;
    cin >> n >> g;

    map<int, int> cows;
    vector<Log> logs;

    rep(n) {
        int day, id, change;
        cin >> day >> id >> change;
        logs.pb({day, id, change});
        cows[id] = g;
    }

    sort(logs.begin(), logs.end());


    map<int, int, greater<int>> cnts;
    cnts[0] = n + 1;

    int result = 0;
    map<int, int> mp;
    for (auto &m : logs) {
        int &ref = mp[m[1]];

        bool wastop = ref == cnts.begin()->first;
        int wascnt = cnts[ref]--;
        if (wascnt == 1) {
            cnts.erase(ref);
        }

        ref += m[2];

        int iscnt = ++cnts[ref];
        bool istop = ref == cnts.begin()->first;
        if (wastop) {
            if (!istop || wascnt != 1 || iscnt != 1) {
                ++result;
            }
        } else if (istop) {
            ++result;
        }
    }
    cout << result << endl;
}
