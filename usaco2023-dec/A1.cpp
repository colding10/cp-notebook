#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int n, m, k;
vector<pi> cows;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int w, a;
        cin >> w >> a;
        cows.push_back(make_pair(-w, a));
    }

    sort(cows.begin(), cows.end());

    int ans = 0;
    vector<int> towers;
    for (int i = 0; i < n; i++) {
        int w, a;
        w = -cows[i].first;
        a = cows[i].second;

        for (int j = 0; j < towers.size(); j++) {
            if (towers[j] - w <= k) {
                towers[j] = w;
                ans++;
            }
        }
        int space = m-towers.size();
        for (int j = 0; j < min(a, space); j++) {
            towers.push_back(w);
            ans++;
        }
    }
    cout << ans << endl;
}
