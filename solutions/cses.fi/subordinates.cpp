#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll, ll>;
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

vector<vi> adj;
vi subtree_size, depth;

void dfs(int v) {
    subtree_size[v] = 1;

    for (auto u : adj[v]) {
        depth[u] = depth[v] + 1;
        dfs(u);
        subtree_size[v] += subtree_size[u];
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    subtree_size.resize(n);
    depth.resize(n);

    FOR(person, 1, n) {
        int manager;
        cin >> manager;
        manager--;

        adj[manager].pb(person);
    }

    dfs(0);
    F0R(i, n) {
        cout << subtree_size[i] - 1 << " ";
    }
    cout << endl;
}
