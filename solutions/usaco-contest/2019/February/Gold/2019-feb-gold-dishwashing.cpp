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

const int MAXN = 1e5 + 5;
vector<int> stacks[MAXN];
int base[MAXN];

int main() {
    setIO("dishes");

    int n;
    cin >> n;

    int mx_placed = 0;
    int ans = n;

    rep(i, 0, n) {
        int x;
        cin >> x;

        if (x < mx_placed) {
            ans = i;
            break;
        }
        for (int j = x; j > 0 && !base[j]; j--) {
            base[j] = x;
        }
        while (!stacks[base[x]].empty() && stacks[base[x]].back() < x) {
            mx_placed = stacks[base[x]].back();
            stacks[base[x]].pop_back();
        }
        stacks[base[x]].push_back(x);
    }
    cout << ans << endl;

    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
