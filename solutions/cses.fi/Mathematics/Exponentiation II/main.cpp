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
		long long a, b, c;
		cin >> a >> b >> c;
		cout << binpow(a, binpow(b, c, 1000000007), 1000000007) << endl;
	}
}
