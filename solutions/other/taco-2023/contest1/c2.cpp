#include <climits>
#include <iostream>
using namespace std;

const int MAX = 1000005;
int dp[MAX];

int minButtonPresses(int n) {
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << minButtonPresses(n) << endl;

    return 0;
}
