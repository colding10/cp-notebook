#include "SCC.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TwoSAT {
public:
    TwoSAT(int n) : n(n), scc(2 * n) {}

    void addClause(int var1, bool b1, int var2, bool b2) {
        scc.add_edge(var1 * 2 + b1, var2 * 2 + !b2);
        scc.add_edge(var2 * 2 + b2, var1 * 2 + !b1);
    }

    bool solve() {
        scc.solve();

        assignment.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (scc.component[2 * i] == scc.component[2 * i + 1])
                return false;
            assignment[i] = scc.component[2 * i] > scc.component[2 * i + 1];
        }
        return true;
    }

    int n;
    SCC scc;
    vector<bool> assignment;
};
