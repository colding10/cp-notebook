#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;
#define MAXN 1000001
int dp[MAXN] = {0};

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        for (int c : coins) {
            int val = i + c;
            if (val > x) {
                continue;
            }

            dp[val] = (dp[val] + dp[i]) % MOD;
        }
    }

    cout << dp[x] << endl;
}
