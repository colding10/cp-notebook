#include <bits/stdc++.h>
#include <queue>
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

int main() {
    int n;
    cin >> n;

    vi a(n);
    for (int &x : a) {
        cin >> x;
    }

    priority_queue<int, vi, greater<int>> pq;
    for (int i = 0; i < n; i += 2) {
        pq.push(a[i]);
        pq.push(a[i + 1]);

        pq.pop();
    }

    ll out = 0;
    while (pq.size()) {
        out += pq.top();
        pq.pop();
    }

    cout << out << endl;
}
