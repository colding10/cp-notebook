#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int dp[1000001];


int main() {
	int n, x;
	cin >> n >> x;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) { cin >> coins[i]; }
	for (int i = 0; i <= x; i++) { dp[i] = 1000000000; }


	dp[0] = 0;
	
	for (int i = 1; i <= x; i++) {
		for (int coin : coins) {
			if (i-coin < 0) { continue; }
			dp[i] = min(dp[i], dp[i-coin]+1);
		}
	}
	cout << (dp[x] >= 1000000000 ? -1 : dp[x]) << endl;
	return 0;
}
