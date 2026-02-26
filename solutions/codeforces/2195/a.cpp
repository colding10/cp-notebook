#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        bool found = false;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x == 67) found = true;
        }
        puts(found ? "YES" : "NO");
    }
}
