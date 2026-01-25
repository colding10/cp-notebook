#include <iostream>
#include <vector>

using namespace std;

#define MAXN 5000

int cc[MAXN][MAXN] = {{}};
bool visited[MAXN][MAXN] = {{}};
bool graph[MAXN][MAXN] = {{}}; // true for blocked
int cc_count = 0;

vector<pair<int, int>> getNeigh(int x, int y, int n) {
    vector<pair<int, int>> out;
    if (x > 1) out.push_back(make_pair(x - 1, y));
    if (y > 1) out.push_back(make_pair(x, y - 1));
    if (x < n) out.push_back(make_pair(x + 1, y));
    if (y < n) out.push_back(make_pair(x, y + 1));
    return out;
}

void floodfill(int x, int y, int n, bool from_neigh = false) {
    if (x < 1 || x > n || y < 1 || y > n || visited[x][y] || graph[x][y]) {
        return;
    }

    if (!from_neigh) {
        cc_count++;
    }

    visited[x][y] = true;
    cc[x][y] = cc_count;

    for (auto p : getNeigh(x, y, n)) {
        floodfill(p.first, p.second, n, true);
    }
}

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int n;
    cin >> n;

    int currx = n / 2 + 1;
    int curry = n / 2 + 1;

    char d;
    for (int i = 0; i < n; i++) {
        graph[currx][curry] = true;

        cin >> d;
        if (d == 'N') {
            curry++;
        } else if (d == 'S') {
            curry--;
        } else if (d == 'E') {
            currx++;
        } else if (d == 'W') {
            currx--;
        }
    }

    for (int x = 1; x <= n + 1; x++) {
        for (int y = 1; y <= n + 1; y++) {
            floodfill(x, y, n);
        }
    }

    cout << cc_count << endl;
}
