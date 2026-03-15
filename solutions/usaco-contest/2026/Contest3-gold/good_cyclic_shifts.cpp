#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BIT {
  public:
    BIT(int n) : n(n + 1), m_array(n + 1, 0) {}

    ll prefix_query(int idx) {
        ll result = 0;
        for (; idx > 0; idx -= idx & -idx)
            result += m_array[idx];
        return result;
    }

    void update(int idx, ll add) {
        for (++idx; idx < n; idx += idx & -idx)
            m_array[idx] += add;
    }

  private:
    vector<ll> m_array;
    int n;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<ll> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
            p[i]--;
        }

        if (N == 1) {
            cout << "1\n0\n";
            continue;
        }

        BIT bit(N);
        ll inv = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (p[i] > 0) inv += bit.prefix_query(p[i]);
            bit.update(p[i], 1);
        }

        ll f = 0;
        for (int i = 0; i < N; i++)
            f += abs(p[i] - i);
        f /= 2;

        ll g = inv - f;

        vector<ll> diff(N + 1, 0);
        for (int k = 0; k < N; k++) {
            int cnt = p[k];
            if (cnt == 0) continue;
            int s0 = (N - k) % N;
            if (s0 + cnt <= N) {
                diff[s0]++;
                diff[s0 + cnt]--;
            } else {
                diff[s0]++;
                diff[0]++;
                diff[(s0 + cnt) % N]--;
            }
        }

        vector<ll> R(N);
        R[0] = diff[0];
        for (int s = 1; s < N; s++)
            R[s] = R[s - 1] + diff[s];

        vector<ll> good;
        if (g == 0) good.push_back(0);
        for (int s = 0; s < N - 1; s++) {
            g += p[N - 1 - s] - N + 1 + R[s];
            if (g == 0) good.push_back(s + 1);
        }

        cout << good.size() << "\n";
        for (int i = 0; i < good.size(); i++) {
            if (i) cout << " ";
            cout << good[i];
        }
        cout << "\n";
    }
}
