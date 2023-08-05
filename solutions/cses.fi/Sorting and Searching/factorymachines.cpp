#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    ll ans_max = *max_element(machines.begin(), machines.end()) * k + 100;
    ll l = 1, r = ans_max;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += mid / machines[i];
            if (cnt >= k) {
                break;
            }
        }
        if (cnt >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
        ans_max = min(ans_max, r);
    }

    cout << l << endl;
    return 0;
}
