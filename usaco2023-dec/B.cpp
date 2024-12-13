#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;
vector<vector<int> > adj;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;

    vector<int> a(k), b(k);
    
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int cur = 0;
        rotate(b.rbegin(), b.rbegin()+i, b.rend());
        for (int j = 0; j < k; j++) {
            cur += a[j]==b[j];
        }
        result=max(result, cur);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < k; i++) {
        int cur = 0;
        rotate(b.rbegin(), b.rbegin()+i, b.rend());
        for (int j = 0; j < k; j++) {
            cur += a[j]==b[j];
        }
        result=max(result, cur);
    }
    // cout << "overlap: " << result << endl;
    int ans = n;
    ans -= 2*(k-result);

    cout << ans << endl;
}

