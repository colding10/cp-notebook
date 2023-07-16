#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    vi evens, odds;

    vi dist(n, -1);
    dist[0] = 0;

    rep(m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] & 1) {
            odds.pb(u);
        } else {
            evens.pb(u);
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (size(odds) < size(evens)) {
        cout << odds.size() << endl;
        for (int x : odds) {
            cout << x + 1 << " ";
        }
        cout << endl;
    } else {
        cout << evens.size() << endl;
        for (int x : evens) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
