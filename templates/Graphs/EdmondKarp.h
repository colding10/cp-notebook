#include <bits/stdc++.h>
using namespace std;

class EdmondKarp {
  public:
    EdmondKarp(int n, vector<vector<int>> capacity)
        : n(n), capacity(capacity) {}

    int maxflow(int s, int t) {
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (capacity[i][j] || capacity[j][i]) adj[i].push_back(j);
            }
        }

        int flow = 0;

        vector<int> parent(n);
        int new_flow;

        while ((new_flow = bfs(s, t, parent))) {
            flow += new_flow;
            int node = t;
            while (node != s) {
                int prev = parent[node];
                capacity[prev][node] -= new_flow;
                capacity[node][prev] += new_flow;
                node = prev;
            }
        }

        return flow;
    }

    int bfs(int s, int t, vector<int> &parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, numeric_limits<int>::max()});

        while (!q.empty()) {
            int node, flow;
            tie(node, flow) = q.front();
            q.pop();

            for (auto next : adj[node]) {
                if (parent[next] == -1 && capacity[node][next]) {
                    parent[next] = node;
                    int new_flow = min(flow, capacity[node][next]);
                    if (next == t) return new_flow;
                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }

    int n;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;
};
