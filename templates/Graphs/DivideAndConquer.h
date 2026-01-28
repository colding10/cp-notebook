#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> subtree_sizes;
vector<bool> blocked;

int compute_subtree_sizes(int v, int p) {
    int size = 1;
    for (int u : adj[v]) {
        if (u != p && !blocked[u]) size += compute_subtree_sizes(u, v);
    }
    return subtree_sizes[v] = size;
}

ll solve(int v) {
    int size = compute_subtree_sizes(v, v);
    bool pushed = true;
    int p = -1;
    while (pushed) {
        pushed = false;
        for (int u : adj[v]) {
            if (u != p && !blocked[u] && subtree_sizes[u] > size / 2) {
                pushed = true;
                p = v;
                v = u;
                break;
            }
        }
    }

    long long result = 0;
    // compute result for node v and all unblocked children

    blocked[v] = true;
    for (int u : adj[v]) {
        if (!blocked[u]) result += solve(u);
    }

    return result;
}
