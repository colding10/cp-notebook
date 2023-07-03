#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;


int last_true(int lo, int hi, function<bool(int)> f) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) { // works
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}


int solve_test_case(int n, int tc, int tm, vector<int> a, vector<int> b, vector<long long> c) {
    int ans = INF;
    int lo = 0, hi = 1000;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool possible = false;

        for (int y = 0; y <= 1000; ++y) {
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                int time_required = max(a[i] * (tc - mid), 0) + max(b[i] * (tm - y), 0);
                if (time_required > c[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                possible = true;
                ans = min(ans, mid + y);
                break;
            }
        }

        if (possible) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        int n, tc, tm;
        cin >> n >> tc >> tm;

        vector<int> a(n), b(n);
        vector<long long> c(n);

        for (int j = 0; j < n; ++j) {
            cin >> a[j] >> b[j] >> c[j];
        }

        int ans = solve_test_case(n, tc, tm, a, b, c);
        cout << ans << endl;
    }

    return 0;
}
