#include <bits/stdc++.h>
using namespace std;

inline double flog(int c) { return c > 0 ? c * log2((double)c) : 0.0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, M = 0;
    cin >> n;
    unordered_map<string, int> tid;
    int tcnt = 1;
    vector<pair<vector<int>, int>> pos;
    
    for (int i = 0; i < n; i++) {
        int m; cin >> m; M = max(M, m);
        vector<int> tk(m);
        for (int j = 0; j < m; j++) {
            string s; cin >> s;
            auto [it, ins] = tid.try_emplace(s, tcnt);
            if (ins) tcnt++;
            tk[j] = it->second;
        }
        string e; cin >> e;
        for (int j = 0; j < m; j++) if (e[j] == 'L') {
            vector<int> rp(tk.begin(), tk.begin() + j);
            reverse(rp.begin(), rp.end());
            pos.emplace_back(move(rp), tk[j]);
        }
    }
    
    int P = pos.size(), maxLen = M - 1;
    vector<int> ord(P);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        auto &x = pos[a].first, &y = pos[b].first;
        for (size_t i = 0; i < min(x.size(), y.size()); i++)
            if (x[i] != y[i]) return x[i] < y[i];
        return x.size() < y.size();
    });
    
    vector<int> lcp(max(0, P - 1));
    for (int i = 0; i + 1 < P; i++) {
        auto &a = pos[ord[i]].first, &b = pos[ord[i+1]].first;
        int l = 0;
        while (l < (int)min(a.size(), b.size()) && a[l] == b[l]) l++;
        lcp[i] = l;
    }
    
    vector<int> par(P);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x) { return par[x] == x ? x : par[x] = find(par[x]); };
    
    vector<map<int,int>> dist(P);
    vector<int> tot(P, 1);
    vector<double> grpLoss(P, 0.0);
    for (int i = 0; i < P; i++) dist[i][pos[ord[i]].second] = 1;
    
    vector<vector<int>> edgesByLcp(maxLen + 1);
    for (int i = 0; i + 1 < P; i++) edgesByLcp[min(lcp[i], maxLen)].push_back(i);
    
    double totalLoss = 0.0;
    vector<double> ans(M, 0.0);
    
    for (int k = maxLen; k >= 0; k--) {
        for (int i : edgesByLcp[k]) {
            int a = find(i), b = find(i + 1);
            if (a != b) {
                totalLoss -= grpLoss[a] + grpLoss[b];
                if (dist[a].size() < dist[b].size()) swap(a, b);
                for (auto& [t, c] : dist[b]) dist[a][t] += c;
                tot[a] += tot[b];
                par[b] = a;
                double s = 0;
                for (auto& [_, c] : dist[a]) s += flog(c);
                grpLoss[a] = flog(tot[a]) - s;
                totalLoss += grpLoss[a];
                dist[b].clear();
            }
        }
        ans[k] = totalLoss;
    }
    
    cout << fixed << setprecision(12);
    for (int k = 0; k < M; k++) cout << ans[k] << '\n';
}
