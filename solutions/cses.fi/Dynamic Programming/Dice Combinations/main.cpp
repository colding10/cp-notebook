#include <iostream>

using namespace std;

const long long MOD = 1000000007;
long long dp[1000001];

int main() {
    int n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;
}
