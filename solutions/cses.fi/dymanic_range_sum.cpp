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

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = data[2 * idx] + data[2 * idx + 1];
    }

    void update(int idx, int value) {
        idx += n;
        data[idx] = value;

        while (idx > 1) {
            idx /= 2;
            data[idx] = data[2 * idx] + data[2 * idx + 1];
        }
    }

    int sum(int left, int right) { // interval [left, right)
        ll ret = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1)
                ret += data[left++];
            if (right & 1)
                ret += data[--right];
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<ll> data;
};
int main() {
    ll n, q;
    cin >> n >> q;
    vector<long long int> a(n);
    for (ll &x : a) {
        cin >> x;
    }

    SegmentTree st(a);

    rep(q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            st.update(a, b);
        } else {
            cout << st.sum(a, b) << endl;
        }
    }
}
