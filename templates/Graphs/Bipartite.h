#include <bits/stdc++.h>
using namespace std;
// ---

vector<vector<int>> adj;
vector<int> color;

bool bipartite(int v = 0, int p = -1, int c = 0) {
    if (p == -1) color.assign(adj.size(), -1);

    if (color[v] >= 0) return color[v] == c;
    color[v] = c;

    for (auto u : adj[v]) {
        if (u == p) continue;
        if (!bipartite(u, v, c ^ 1)) return false;
    }

    return true;
}
