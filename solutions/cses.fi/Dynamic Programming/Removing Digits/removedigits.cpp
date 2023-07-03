#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

#define MAXN 1000000
const int INF = 1e9;
int dp[MAXN];
set<int> visited;

set<int> getDigits(int x) {
	ostringstream os;
	os << x;
	
	string digits = os.str();

	set<int> out;
	for (char c : digits) {
		out.insert(c - '0');
	}

	return out;
}


int main() {
	// Initialize dp array with INF
	for (int i = 0; i < MAXN; i++) {
  	  dp[i] = INF;
	}

	int n;
	cin >> n;
	dp[n] = 0;
	for (int i = n; i >= 0; i--) {
		if (dp[i] == INF) {
			continue;
		}

		set<int> digits = getDigits(i);
		for (int d : digits) {
			int j = i - d;
			if (j >= 0) {
				dp[j] = min(dp[j], dp[i] + 1);
			}
		}
	}
	cout << dp[0] << endl;
}
