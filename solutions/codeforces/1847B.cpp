#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll, ll>;
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
    int n;
    cin >> n;
    vector<int> vamp(n);
    for (int &x : vamp) {
        cin >> x;
    }

    int min_stength = *min_element(vamp.begin(), vamp.end());

    int group_count = -1;
    int strength_sum = 0;

    FOR(i, 0, n) {
        if ((vamp[i] & min_stength) == min_stength) {
            group_count++;
        }
        strength_sum += vamp[i];
    }

    cout << group_count << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
