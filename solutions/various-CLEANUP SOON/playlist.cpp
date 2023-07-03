#include <bits/stdc++.h>

using namespace std;

int N;
set<int> songs;

vector<int> order;

int main() {
    cin >> N;
    order.resize(N);
    for (int &x : order) {
        cin >> x;
    }

    int ans = 0;
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && !songs.count(order[r])) {
            songs.insert(order[r]);
            r++;
        }

        ans = max(ans, r - l);
        songs.erase(order[l]);
    }

    cout << ans << endl;
}
