#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<long long> f(n + 1);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &f[i]);

        vector<long long> a(n + 1);

        if (n == 2) {
            a[1] = f[2];
            a[2] = f[1];
        } else {
            for (int x = 1; x <= n - 2; x++)
                a[x + 1] = (f[x + 2] - 2 * f[x + 1] + f[x]) / 2;

            long long k1 = 0;
            for (int i = 2; i <= n - 1; i++)
                k1 += a[i] * (i - 1);
            a[n] = (f[1] - k1) / (n - 1);

            long long kn = 0;
            for (int i = 2; i <= n - 1; i++)
                kn += a[i] * (n - i);
            a[1] = (f[n] - kn) / (n - 1);
        }

        for (int i = 1; i <= n; i++)
            printf("%lld%c", a[i], " \n"[i == n]);
    }
    return 0;
}
