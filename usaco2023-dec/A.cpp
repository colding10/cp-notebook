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
    int towerc = 0;
    vector<pi> towers;

    for (int i = 0; i < n; i++) {
        int w, a;
        w = -cows[i].first;
        a = cows[i].second;

        int space = m-towerc;
        if (space) {
            towers.push_back(make_pair(w, min(a, space)));
            ans += min(a, space);
            towerc += min(a, space);
            a -= min(a, space);
        }

        for (int j = 0; j < towers.size(); j++) {
            if (towers[j].first - w >= k) {
                if (a < towers[j].second) { // dont have enough cows
                    towers.push_back(make_pair(w, a));
                }

                towers[j].first = w;
                towers[j].second = min(a, towers[j].second);
                a -= min(a, towers[j].second);
                ans+=towers[j].second;
            }
        }
    }
    cout << ans << endl;
}