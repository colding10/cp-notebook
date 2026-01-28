#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
    int n;
    vector<vector<int>> adj;
    vector<int> subtree_size;
    vector<bool> removed;
    vector<int> centroid_parent;
    int root;

    CentroidDecomposition(int n)
        : n(n), adj(n), subtree_size(n), removed(n, false),
          centroid_parent(n, -1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int get_subtree_size(int v, int p = -1) {
        subtree_size[v] = 1;
        for (int u : adj[v]) {
            if (u != p && !removed[u]) {
                subtree_size[v] += get_subtree_size(u, v);
            }
        }
        return subtree_size[v];
    }

    int get_centroid(int v, int tree_size, int p = -1) {
        for (int u : adj[v]) {
            if (u != p && !removed[u] && subtree_size[u] > tree_size / 2) {
                return get_centroid(u, tree_size, v);
            }
        }
        return v;
    }

    void build(int v = 0, int p = -1) {
        int tree_size = get_subtree_size(v);
        int centroid = get_centroid(v, tree_size);
        centroid_parent[centroid] = p;
        if (p == -1) root = centroid;
        removed[centroid] = true;

        for (int u : adj[centroid]) {
            if (!removed[u]) {
                build(u, centroid);
            }
        }
    }

    // Override this to process paths through centroid
    // Call build() first, then use centroid_parent to traverse up the centroid
    // tree
};
