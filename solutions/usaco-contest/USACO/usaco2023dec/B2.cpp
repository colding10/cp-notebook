#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(K), b(K);

    for (int i = 0; i < K; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < K; ++i) {
        cin >> b[i];
    }

    int maxFixedPoints = longestCommonSubsequence(a, b);
    cout << maxFixedPoints << endl;

    return 0;
}
