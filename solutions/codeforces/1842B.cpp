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
    int n, x;
    cin >> n >> x;

    int current = 0;
    vi books(n * 3);
    for (int &x : books) {
        cin >> x;
    }

    int s1 = 0;
    int s2 = 0;
    int s3 = 0;

    for (int i = 0; i < n; i++) {
        int book = books[i];
        if ((x | book) == x) { // valid
            s1 |= book;
        } else {
            break;
        }
    }
    for (int i = n; i < 2 * n; i++) {
        int book = books[i];
        if ((x | book) == x) { // valid
            s2 |= book;
        } else {
            break;
        }
    }

    for (int i = n * 2; i < 3 * n; i++) {
        int book = books[i];
        if ((x | book) == x) { // valid
            s3 |= book;
        } else {
            break;
        }
    }

    if ((s1 | s2 | s3) == x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
