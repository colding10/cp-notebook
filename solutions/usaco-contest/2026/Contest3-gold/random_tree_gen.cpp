#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll mod) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return power(a, MOD - 2, MOD); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> sz(n + 1, 1);
        vector<int> par(n + 1, 0), order;
        order.reserve(n);
        vector<bool> vis(n + 1, false);

        queue<int> q;
        q.push(1);
        vis[1] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    par[v] = u;
                    q.push(v);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (par[u]) sz[par[u]] += sz[u];
        }

        ll inv_P_root = 1;
        for (int i = 1; i <= n; i++) {
            inv_P_root = inv_P_root % MOD * inv(sz[i]) % MOD;
        }

        vector<ll> inv_P(n + 1, 0);
        inv_P[1] = inv_P_root;
        ll ans = inv_P_root;
        for (int i = 1; i < n; i++) {
            int c = order[i];
            int u = par[c];
            inv_P[c] = inv_P[u] % MOD * sz[c] % MOD * inv(n - sz[c]) % MOD;
            ans = (ans + inv_P[c]) % MOD;
        }

        ll fact = 1;
        for (ll i = 2; i <= n - 1; i++)
            fact = fact * i % MOD;
        ans = ans % MOD * inv(fact) % MOD;

        cout << ans << "\n";
    }
}
