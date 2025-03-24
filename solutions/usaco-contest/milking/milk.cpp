/*
TASK: milk2
LANG: C++
ID: colindi1
*/
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

bool cond(const pi&a, const pi&b) {
    if (a.fi != b.fi) {
        return a.fi < b.fi;
    } else {
        return a.se < b.se;
    }
}

struct Event {
    int starting, ending;

    Event(int start, int end) : starting(start), ending(end) {}

    // For debugging purposes
    void print() const {
        std::cout << "<Event> (starting=" << starting << ", ending=" << ending << ")\n";
    }
};


int main() {
    setIO(
        "milk2"
    );

    int n;
    cin >> n;
    std::vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        events.emplace_back(start, end);
    }    

    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.starting < b.starting || (a.starting == b.starting && a.ending < b.ending);
    });

    std::vector<Event> mergedEvents;
    Event previousEvent = events[0];

    for (size_t i = 1; i < events.size(); ++i) {
        const Event& currentEvent = events[i];
        if (currentEvent.starting <= previousEvent.ending) {
            previousEvent.ending = std::max(previousEvent.ending, currentEvent.ending);
        } else {
            mergedEvents.push_back(previousEvent);
            previousEvent = currentEvent;
        }
    }
    mergedEvents.push_back(previousEvent); // Add the last merged interval

    // Calculate maximum milking and not-milking times
    int maximumMilking = INT_MIN;
    int maximumNotMilking = INT_MIN;

    // Initial comparison event
    previousEvent = Event(0, mergedEvents[0].starting);

    for (const Event& event : mergedEvents) {
        int milkingTime = event.ending - event.starting;
        int notMilkingTime = event.starting - previousEvent.ending;

        maximumMilking = std::max(maximumMilking, milkingTime);
        maximumNotMilking = std::max(maximumNotMilking, notMilkingTime);

        previousEvent = event;
    }

    // Output the results
    cout << maximumMilking << " " << maximumNotMilking << "\n";

    return 0;
}

// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
