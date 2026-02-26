#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<int> dp(7);
        for (int v = 1; v <= 6; v++)
            dp[v] = (v != a[0]);

        for (int i = 1; i < n; i++) {
            vector<int> ndp(7, n);
            for (int v = 1; v <= 6; v++) {
                int cost = (v != a[i]);
                for (int u = 1; u <= 6; u++) {
                    if (u != v && u + v != 7)
                        ndp[v] = min(ndp[v], dp[u] + cost);
                }
            }
            dp = ndp;
        }

        printf("%d\n", *min_element(dp.begin() + 1, dp.end()));
    }
}
