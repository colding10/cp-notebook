#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    F0R(i, n) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = INT_MAX;

    int segsize = 0;
    int msegsize = -1;
    vi segs;
    F0R(lptr, n - 1) {
        segsize++;
        if (a[lptr + 1] - a[lptr] > k) {
            segs.pb(segsize);
            msegsize = max(msegsize, segsize);
            segsize = 0;
        }
    }

    segs.pb(segsize+1);
    msegsize = max(msegsize, segsize+1);

    
    if (segs.size() == 1) {
        cout << 0 << endl;
        return;
    }
    // ans = min(ans, n - segs[0]);
    // ans = min(ans, n - segs.back());
    //
    // cout << ans << endl;
    cout << (n-msegsize) << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you thinkbably simpler than you think
