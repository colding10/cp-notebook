#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
using ll = long long int;

int main() {
    ll R, C, M;
    cin >> R >> C >> M;
    
    // Input validation
    if (R <= 0 || C <= 0 || M <= 0) {
        cout << "Invalid input" << endl;
        return 1;
    }

    // Use vector instead of VLA
    vector<vector<ll>> dp(R, vector<ll>(C));
    
    for (int c = 0; c < C; c++) {
        dp[0][c] = c%M + 1;
    }

    for (int r = 1; r < R; r++) {
        for (int c = 0; c < C; c++) {
            ll cost = (C * r + c) % M + 1;
            ll min_prev = dp[r-1][c];

            if (c > 0) {
                min_prev = min(min_prev, dp[r-1][c-1]);
            }
            if (c < C-1) {
                min_prev = min(min_prev, dp[r-1][c+1]);
            }
            dp[r][c] = cost + min_prev;
        }
    }

    ll ans = INT64_MAX;
    for (int c = 0; c < C; c++) {
        ans = min(ans, dp[R-1][c]);
    }
    cout << ans << endl;
    return 0;
}