#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    ll K;

    cin >> N >> K;

    vector<ll> a(N), b(N);
    ll sa = 0, sb = 0, ma = 0, mb = 2000000000LL;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sa += a[i];
        ma = max(ma, a[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        sb += b[i];
        mb = min(mb, b[i]);
    }

    ll Dhi = ma - mb;
    ll num = sa - sb - 2 * K;
    ll Dlo = (num >= 0) ? (num + N - 1) / N : num / N;

    vector<ll> ev(2 * N);

    auto check = [&](ll D) -> bool {
        for (int i = 0; i < N; i++) {
            ll p = a[i], q = D + b[i];
            if (p <= q) {
                ev[2 * i] = p + 1;
                ev[2 * i + 1] = q + 1;
            } else {
                ll s = p + q;
                ll f = (s >= 0) ? s / 2 : (s - 1) / 2;
                ev[2 * i] = f + 1;
                ev[2 * i + 1] = (s % 2 == 0) ? f + 1 : f + 2;
            }
        }
        nth_element(ev.begin(), ev.begin() + N - 1, ev.end());
        ll M = ev[N - 1] - 1;
        ll tot = 0;
        for (int i = 0; i < N; i++) {
            ll v = max({0LL, a[i] - M, M - D - b[i]});
            tot += v;
            if (tot > K) {
                return false;
            }
        }
        return true;
    };

    ll lo = Dlo, hi = Dhi;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
// look at the paper instead of staring here
