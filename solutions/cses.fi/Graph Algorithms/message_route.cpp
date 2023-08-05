#include <bits/stdc++.h>
#include <cmath>
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

int n, m;
vector<bool> visited;
vector<int> prev_step;
vector<vector<int>> adj;

int main() {
    setIO();

    cin >> n >> m;

    adj.rsz(n);
    visited.rsz(n, false);
    prev_step.rsz(n);

    rep(m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;
    visited[0] = true;

    q.push(0);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if (v == n - 1) {
            break;
        }

        for (auto n : adj[v]) {
            if (visited[n]) continue;

            visited[n] = true;
            prev_step[n] = v;

            q.push(n);
        }
    }

    int begin = 0;
    int end = n - 1;

    if (visited[n - 1]) {
        vector<int> steps;
        while (begin != end) {
            steps.pb(end + 1);
            end = prev_step[end];
        }
        steps.pb(1);

        reverse(steps.begin(), steps.end());
        cout << sz(steps) << endl;
        for (int c : steps) {
            cout << c << " ";
        }

        cout << endl;

    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    // you should actually read the stuff at the bottom
}
