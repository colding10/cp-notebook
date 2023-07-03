#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int N, X;
	cin >> N >> X;
	vector<int> T(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}
 
	long long prefix_sum = 0;
	long long ans = 0;
	map<long long, int> sums;
	sums[0] = 1;
	for (int x : T) {
		prefix_sum += x;
		/*
		 * If there is a subarray with a prefix sum of prefix_sum - X,
		 * we can exclude it from our current subarray to get the desired sum.
		 * Thus, we can add the number of those subarrays to our answer.
		 */
		ans += sums[prefix_sum - X];
		// Increment the amount of prefix sums with a sum of prefix_sum
		sums[prefix_sum]++;
	}
	cout << ans << endl;
}
