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
    char l1[4];
    char l2[4];
    char l3[4];

    cin >> l1 >> l2 >> l3;

    // cols
    F0R(i, 3) {
        if (l1[i] == l2[i] && l2[i] == l3[i] && l1[i] != '.') {
            cout << l1[i] << endl;
            return;
        }
    }

    if (l1[0] == l1[1] && l1[1] == l1[2] && l1[0] != '.') {
        cout << l1[0] << endl;
        return;
    }
    if (l2[0] == l2[1] && l2[1] == l2[2] && l2[0] != '.') {
        cout << l2[0] << endl;
        return;
    }

    if (l3[0] == l3[1] && l3[1] == l3[2] && l3[0] != '.') {
        cout << l3[0] << endl;
        return;
    }

    if (l1[0] == l2[1] && l2[1] == l3[2] && l1[0] != '.') {
        cout << l1[0] << endl;
        return;
    }
    if (l1[2] == l2[1] && l2[1] == l3[0] && l1[2] != '.') {
        cout << l1[2] << endl;
        return;
    }

    cout << "DRAW" << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
