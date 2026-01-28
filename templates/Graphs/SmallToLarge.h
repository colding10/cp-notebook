#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ---
// Small-to-Large Merging (DSU on Tree / Sack)
// Use when you need to answer queries about subtrees
// Time: O(n log n)

vector<vector<int>> adj;
vector<int> subtree_size, big_child;
int n;

void calc_sizes(int v, int p = -1) {
    subtree_size[v] = 1;
    big_child[v] = -1;
    for (int u : adj[v]) {
        if (u == p) continue;
        calc_sizes(u, v);
        subtree_size[v] += subtree_size[u];
        if (big_child[v] == -1 ||
            subtree_size[u] > subtree_size[big_child[v]]) {
            big_child[v] = u;
        }
    }
}

// Global data structure for current subtree (e.g., map<int,int> cnt for
// counting colors) map<int, int> cnt; int answer;

void add(int v, int p, int x) {
    // Add node v to the data structure
    // cnt[color[v]] += x;
    for (int u : adj[v]) {
        if (u != p) add(u, v, x);
    }
}

void dfs(int v, int p, bool keep) {
    // Process small children first, don't keep their contributions
    for (int u : adj[v]) {
        if (u != p && u != big_child[v]) {
            dfs(u, v, false);
        }
    }

    // Process big child, keep its contributions
    if (big_child[v] != -1) {
        dfs(big_child[v], v, true);
    }

    // Add current node and small children to data structure
    // cnt[color[v]]++;
    for (int u : adj[v]) {
        if (u != p && u != big_child[v]) {
            add(u, v, 1);
        }
    }

    // Answer query for node v here
    // ans[v] = ...

    // If not keeping, remove all contributions
    if (!keep) {
        // cnt[color[v]]--;
        for (int u : adj[v]) {
            if (u != p) add(u, v, -1);
        }
    }
}

void solve() {
    // calc_sizes(0);
    // dfs(0, -1, false);
}
