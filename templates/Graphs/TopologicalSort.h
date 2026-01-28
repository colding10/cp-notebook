#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace TopologicalSort {
using AdjacencyList = vector<vector<int>>;
vector<bool> visited;
vector<int> order;

void dfs(int v, AdjacencyList const &adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u, adj);
    }
    order.push_back(v);
}

vector<int> sort(AdjacencyList const &adj) {
    int n = adj.size();
    order.clear();
    order.reserve(n);
    visited.assign(n, false);
    for (int v = 0; v < n; v++) {
        if (!visited[v]) dfs(v, adj);
    }
    reverse(order.begin(), order.end());
    return order;
}
} // namespace TopologicalSort
