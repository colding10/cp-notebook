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

std::vector<long long>
dijkstra(std::vector<std::vector<std::pair<int, long long>>> const &adj,
         int v0) {
    int n = adj.size();
    std::vector<long long> cost(n, -1);
    std::priority_queue<std::pair<long long, int>> pq;
    pq.push({0, v0});
    cost[v0] = 0;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        long long c = -x.first;
        int v = x.second;
        if (c > cost[v]) continue;
        cost[v] = c;
        for (auto next : adj[v]) {
            if (cost[next.first] == -1 || cost[next.first] > c + next.second) {
                cost[next.first] = c + next.second;
                pq.push({-(c + next.second), next.first});
            }
        }
    }
    return cost;
}

void solve() {
    int n, m;
    cin >> n >> m;

    bitset<10> tmp;
    cin >> tmp;
    int v0 = tmp.to_ulong();

    vector<pair<pi, int>> adj(m);
    F0R(i, m) {
        cin >> adj[i].second;
        cin >> tmp;
        adj[i].f.f = ((1 << n) - 1) ^ int(tmp.to_ulong());
        cin >> tmp;
        adj[i].f.s = int(tmp.to_ulong());
    }

    int N = 1 << n;
    vll cost(N, INT_MAX);
    priority_queue<pair<ll, int>> pq;

    pq.push({0, v0});
    cost[v0] = 0;
    while (!pq.empty()) {
        auto [c, v] = pq.top();
        pq.pop();

        c = -c;

        F0R(i, m) {
            int to = v & adj[i].first.first;
            to |= adj[i].first.second;
            if (cost[to] > c + adj[i].second) {
                cost[to] = c + adj[i].second;
                pq.push({-cost[to], to});
            }
        }
    }

    if (cost[0] == INT_MAX) cost[0] = -1;
    cout << cost[0] << endl;
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
