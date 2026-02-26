#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            int vi = i, va = a;
            while (vi % 2 == 0) vi /= 2;
            while (va % 2 == 0) va /= 2;
            if (vi != va) ok = false;
        }
        puts(ok ? "YES" : "NO");
    }
}
