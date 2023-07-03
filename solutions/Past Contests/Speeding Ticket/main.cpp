#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define pb push_back
#define sz(x) (int)(x).size()

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);

    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("speeding");

    int N, M;
    vi limits;
    vi bessie;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int segment_length, speed_limit;
        cin >> segment_length >> speed_limit;

        for (int _ = 0; _ < segment_length; _++) {
            limits.push_back(speed_limit);
        }
    }

    for (int i = 0; i < N; i++) {
        int segment_length, bessie_speed;
        cin >> segment_length >> bessie_speed;

        for (int _ = 0; _ < segment_length; _++) {
            bessie.push_back(bessie_speed);
        }
    }

    int current_maximum = 0;

    for (int i = 0; i < 100; i++) {
        int speed_limit = limits[i];
        int bessie_speed = bessie[i];

        int infraction = bessie_speed - speed_limit;

        current_maximum = max(infraction, current_maximum);
    }
    
    cout << current_maximum << endl;
}