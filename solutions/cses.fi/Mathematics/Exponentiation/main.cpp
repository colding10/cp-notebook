#include <iostream>

using namespace std;

long long binpow(long long x, long long n, long long m) {
	x %= m;
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << binpow(a, b, 1000000007) << endl;
	}
}
