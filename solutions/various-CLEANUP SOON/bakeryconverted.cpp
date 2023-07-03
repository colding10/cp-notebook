#include <bits/stdc++.h>
using namespace std;

class Customer {
public:
    int cookie, muffin, wait_time;

    Customer(int cookie, int muffin, int wait_time) {
        this->cookie = cookie;
        this->muffin = muffin;
        this->wait_time = wait_time;
    }
};

void solution() {
    int N, tC, tM;
    cin >> N >> tC >> tM;
    vector<Customer> cows;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cows.push_back(Customer(a, b, c));
    }
    int l = 2, r = tC + tM;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int up = min(tC, mid - 1);
        int low = max(mid - tM, 1);
        for (const Customer &cow : cows) {
            if (cow.cookie == cow.muffin) {
                if (cow.wait_time < cow.muffin * mid) {
                    up = INT_MIN;
                }
            } else {
                double limit = (static_cast<double>(cow.wait_time) - cow.muffin * mid) /
                               (cow.cookie - cow.muffin);
                if (cow.cookie > cow.muffin) {
                    up = min(static_cast<int>(floor(limit)), up);
                } else {
                    low = max(static_cast<int>(ceil(limit)), low);
                }
            }
        }
        if (up >= low) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    int ans = tC + tM - l;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solution();
    }
    return 0;
}
