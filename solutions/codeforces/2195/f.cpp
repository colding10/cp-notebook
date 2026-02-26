#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<long long> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return c[i] < c[j];
        });

        auto isAbove = [&](int i, int j) -> bool {
            long long da = a[i] - a[j];
            long long db = b[i] - b[j];
            long long dc = c[i] - c[j];
            if (da == 0)
                return db == 0 && dc > 0;
            if (da < 0) return false;
            if (dc <= 0) return false;
            return db * db < 4 * da * dc;
        };

        vector<int> down(n, 1), up(n, 1);

        for (int ii = 0; ii < n; ii++) {
            int i = order[ii];
            for (int jj = 0; jj < ii; jj++) {
                int j = order[jj];
                if (isAbove(i, j))
                    down[i] = max(down[i], down[j] + 1);
            }
        }

        for (int ii = n - 1; ii >= 0; ii--) {
            int i = order[ii];
            for (int jj = ii + 1; jj < n; jj++) {
                int j = order[jj];
                if (isAbove(j, i))
                    up[i] = max(up[i], up[j] + 1);
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d", down[i] + up[i] - 1);
            putchar(i < n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
