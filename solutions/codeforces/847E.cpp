#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

//
// Basic Types
//
using ll = long long;
using db = long double;
using str = string;

//
// Pairs
//
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
define mp make_pair
#define f first
#define s second

//
// Template for types
//
#define tcT template <class T
#define tcTU tcT, class U

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;

//
// Vector Macros
//
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

//
// Vectors
//
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
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

//
// Loops
//
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

//
// Consts
//

const int MOD = (int)1e9 + 7; // 998244353;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(), "r", stdin); }
void setOut(const str &s) { freopen(s.c_str(), "w", stdout); }
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

int N;

bool works(int t, vector<int> &packmen, deque<int> stars) {
    for (int p : packmen) {
        vector<int> need;
        while (!stars.empty() && stars[0] < p) {
            need.pb(stars.front());
            stars.pop_front();
        }

        if (need.empty()) { // going right
            while (!stars.empty() && stars[0] - p <= t) {
                stars.pop_front();
            }
        } else { // have to go left first
            if (p - need[0] > t) {
                return false;
            }

            int left_time = p - need[0];
            int free = t - 2 * left_time;

            int right_free_time = t - 2 * left_time;
            int left_first = -1;
            while (left_first + 1 < stars.size() &&
                   stars[left_first + 1] - p <= right_free_time) {
                left_first++;
            }

            // test for if we went to the right first
            right_free_time = t - left_time;
            int right_first = -1;
            while (right_first + 1 < stars.size() &&
                   (stars[right_first + 1] - p) * 2 <= right_free_time) {
                right_first++;
            }

            // take the maximum
            for (int i = 0; i < std::max(left_first, right_first) + 1; i++) {
                stars.pop_front();
            }
        }
    }

    return stars.empty();
}

int main() {
    setIO();
    int N;
    deque<int> stars;
    vector<int> packmen;

    cin >> N;
    char c;
    F0R(i, N) {
        cin >> c;
        if (c == 'P') {
            packmen.pb(i);
        } else if (c == '*') {
            stars.pb(i);
        }
    }

    int lo = 0;
    int hi = N * 2;
    int res;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (works(mid, packmen, stars)) {
            hi = mid - 1;
            res = mid;
        } else {
            lo = mid + 1;
        }
    }

    if (lo > hi) {
        
    }

    cout << res << endl;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
