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

int main() {
    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << (n - m) << endl;
        return 0;
    }

    int steps = 0;
    while (n != m) {
        if (n >= m) {
            steps += (n - m);
            break;
        }

        if (m & 1) {
            m = (m + 1) / 2;
            steps++;
        } else {
            m /= 2;
        }
        steps++;
    }

    cout << steps << endl;
}
