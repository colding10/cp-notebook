#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

#define mp make_pair
#define f first
#define s second

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

const int MOD = (int)1e9 + 7;                     // 998244353;
const ll BIG = 1e18;                              // not too close to LLONG_MAX
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every grid problem!!
const char dir[4]{'D', 'R', 'U', 'L'}, cdir[4]{'S', 'E', 'N', 'W'};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

int main() {
    setIO();

    int k;
    int n;
    cin >> k >> n;

    vector<int> changes(k + 1);
    vector<int> scores(n);
    for (int i = 1; i <= k; ++i) {
        cin >> changes[i];
        changes[i] += changes[i - 1];
    }
    for (int &p : scores) {
        cin >> p;
    }

    set<int> all_starting;
    for (int m = 1; m <= k; ++m) {
        all_starting.insert(scores.front() - changes[m]);
    }

    int ans = 0;
    for (int s : all_starting) {
        // What all the scores are going to now be given the starting score
        set<int> points;
        for (int i = 1; i <= k; ++i) {
            points.insert(s + changes[i]);
        }

        bool valid = true;
        for (int p : scores) {
            valid &= points.count(p);
        }

        ans += valid;
    }
    cout << ans << endl; // you should actually read the stuff at the bottom
}
