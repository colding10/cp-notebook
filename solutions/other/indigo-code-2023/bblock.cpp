#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    int m = 0;

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        m = max(m, heights[i]);
    }

    int ans = 0;
    for (int height = 1; height <= m; height++) {
        bool block_started = false;
        for (int i = 0; i < n; i++) {
            if (heights[i] < height) {
                block_started = true;
            }
            if (heights[i] == height && block_started && height > 0) {
                ans++;
                block_started = false;
            }
        }
        if (block_started) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
