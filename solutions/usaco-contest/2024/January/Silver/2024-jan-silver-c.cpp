#include <bits/stdc++.h>
#include <climits>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#define int long long
int32_t main() {
    int n;
    cin >> n;
    vector<int> m(n);
    int min_m = LONG_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        min_m = min(min_m, x);
        m[i]=x;
    }

    int uprlmt = min_m / 4;
    int ans = 0;
    for (int x = 1; x <= uprlmt; x++) {
        set<int> modval;

        for (int i = 0; i < n; i++) {
            int y = m[i] % x;
            modval.insert(y);
                if (modval.size() >3){
                    break;
                }
        }
        if (modval.size() <= 3) {
            ans+=x;
        }
    }
    cout << ans << endl;
}