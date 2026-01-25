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



// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
int main() {
    setIO();
    
    int n;
    cin >> n;
    
    vector<char> weather(n);
    for (int i = 0; i < n; ++i) {
        cin >> weather[i];
    }

    // Step 1: Group consecutive 'S' into blocks and keep track of the number of 'S' in each block.
    vector<int> sunny_blocks;
    int current_streak = 0;
    
    // Create the blocks of consecutive 'S'
    for (int i = 0; i < n; ++i) {
        if (weather[i] == 'S') {
            current_streak++;
        } else {
            if (current_streak > 0) {
                sunny_blocks.push_back(current_streak);
            }
            current_streak = 0;
        }
    }
    
    dbg(sunny_blocks);
    // If there was a sunny streak at the end
    if (current_streak > 0) {
        sunny_blocks.push_back(current_streak);
    }

    // If there's no sunny day at all
    if (sunny_blocks.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // Step 2: Calculate the max streak without any changes
    int max_streak = *max_element(sunny_blocks.begin(), sunny_blocks.end()) + 1;

    // Step 3: Try merging two adjacent sunny blocks by changing a single 'P' between them
    for (int i = 1; i < sunny_blocks.size(); ++i) {
        if (weather[sunny_blocks[i-1] + sunny_blocks[i] + 1] == 'P') {
            max_streak = max(max_streak, sunny_blocks[i-1] + sunny_blocks[i] + 1);
        }
    }

    cout << max_streak << endl;
    return 0;
}
