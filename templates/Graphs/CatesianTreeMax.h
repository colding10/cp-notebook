#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int CatesianTreeMax(vector<int> const &A, vector<int> &parent,
                    vector<vector<int>> &adj) {
    int N = A.size();
    parent.assign(N, -1);
    stack<int> s;
    for (int i = 0; i < N; i++) {
        int last = -1;
        while (!s.empty() && A[s.top()] <= A[i]) {
            last = s.top();
            s.pop();
        }
        if (!s.empty()) parent[i] = s.top();
        if (last >= 0) parent[last] = i;
        s.push(i);
    }

    adj.clear();
    adj.resize(N);
    int root = -1;
    for (int i = 0; i < N; i++) {
        if (parent[i] >= 0)
            adj[parent[i]].push_back(i);
        else
            root = i;
    }
    return root;
}
