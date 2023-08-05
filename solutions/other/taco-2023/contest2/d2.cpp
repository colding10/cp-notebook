#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> towers;
    for (int i = 0; i < n; i++) {
        int x, h;
        cin >> x >> h;
        towers.insert(make_pair(x, h));
    }

    vector<int> people(m);
    for (int i = 0; i < m; i++) {
        cin >> people[i];
    }

    for (int i = 0; i < m; i++) {
        int l = 0;
        for (const auto &t : towers) {
            int dist = abs(t.first - people[i]);
            int height = max(0, t.second - dist);
            l = max(l, height);
        }
        cout << l << endl;
    }

    return 0;
}
