void dfs(int v, int p = -1) {
    subtree_size[v] = 1;

    for (auto u : adj[v]) {
        if (u == p) continue;

        depth[u] = depth[v] + 1;
        dfs(u);
        subtree_size[v] += subtree_size[u];
    }
}
