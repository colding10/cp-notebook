
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Customer {
public:
    long long int cookie, muffin, wait_time;

    Customer(long long int a, long long int b, long long int c) {
        cookie = a;
        muffin = b;
        wait_time = c;
    }
};

void solution() {
    long long int N, tC, tM;
    cin >> N >> tC >> tM;
    vector<Customer> cows;
    for (long long int i = 0; i < N; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        cows.push_back(Customer(a, b, c));
    }
    long long int l = 2, r = tC + tM;
    while (l < r) {
        long long int mid = (l + r + 1) / 2;
        long long int up = min(tC, mid - 1), low = max(mid - tM, 1LL);
        for (const auto &cow : cows) {
            if (cow.cookie == cow.muffin) {
                if (cow.wait_time < cow.muffin * mid) {
                    up = LLONG_MIN;
                }
            } else {
                long long int limit =
                    (cow.wait_time - cow.muffin * mid) / (cow.cookie - cow.muffin);
                if (cow.cookie > cow.muffin) {
                    up = min(static_cast<long long int>(floor(limit)), up);
                } else {
                    low = max(static_cast<long long int>(ceil(limit)), low);
                }
            }
        }
        if (up >= low) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    long long int ans = tC + tM - l;
    cout << ans << endl;
}

int main() {
    long long int T;
    cin >> T;
    for (long long int i = 0; i < T; i++) {
        solution();
    }
    return 0;
}
