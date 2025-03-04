#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> potions;
vector<vector<int> > adj;

set<int> children;
vector<bool> visited_child;

void find_children(int v, int p) {
    if (adj[v].size() == 1) {
        children.insert(v);
    }

    for (int u : adj[v]) {
        if (u != p) {
            find_children(u, v);
        }
    }
}

bool dfs(int v, int p) {
    if (adj[v].size() == 1 && children.count(v)) {
        if (!visited_child[v]) {
            visited_child[v] = true;
            // cout << "found child: " << v << endl;
            return true;
        }
    }


    for (int u : adj[v]) {
        if (u != p && u != 0) {
            if (dfs(u, v)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;
    potions.resize(n);
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        potions[i] = x-1;
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--,b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_children(0, -1);
    int moves = children.size();
    visited_child.resize(n);

    int ans = 0;
    for (int m = 0; m < moves; m++) {
        int pot = potions[m];
        // cout << "looking from pot at: " << pot << endl;
        if (dfs(pot, -1)) {
            ans++;
        }
    }
    cout << ans << endl;
}