#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> inv(ll n) {
    vector<ll> ans;
    ans.push_back(4000000000000000000);
    for (int i = 0; i < 111; i++) {
        ans.push_back(n);
        n = (2 * n + 4) / 3 - 2;
    }
    return ans;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll l1, r1, l2, r2, t;
        cin >> l1 >> r1 >> l2 >> r2 >> t;

        ll ans = 0;
        vector<ll> inv1 = inv(t - 1);
        vector<ll> inv2 = inv(l2 + t - 1);
        vector<ll> inv3 = inv(r2 + t);
        for (int j = 1; j < 111; j++) {
            // l1 <= i <= min(t/2,r1)
            // 3*i-1 <= min(inv1[j-1],inv3[j])
            // 3*i-1 > inv2[j]
            ll low = max(l1, (inv2[j] + 4) / 3);
            ll high =
                min(min(t / 2, r1), (min(inv1[j - 1], inv3[j]) + 4) / 3 - 1);
            ans += max(0LL, high - low + 1);
        }

        // l1 <= i <= r1
        // l2 <= i <= r2
        // t <= 2*i-1
        ans += max(0LL, min(r1, r2) - max(max(l1, l2), t / 2 + 1) + 1);
        cout << ans << endl;
    }
}
