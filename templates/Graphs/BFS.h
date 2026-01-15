#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

vector<int> bfs(int start) {
    int n = adj.size();
    vector<bool> found(n, false);
    queue<pair<int, int>> q;
    vector<int> dist_to_start(n);

    q.push({start, 0});
    found[start] = true;

    while (!q.empty()) {
        auto p = q.front();
        int cur = p.first;
        int dist = p.second;
        q.pop();

        dist_to_start[cur] = dist;

        for (auto next : adj[cur]) {
            if (!found[next]) {
                q.push({next, dist + 1});
                found[next] = true;
            }
        }
    }

    return dist_to_start;
}
