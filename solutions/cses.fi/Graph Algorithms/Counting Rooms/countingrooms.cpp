#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define MAXN 1005

int cc_count = 0;
bool grid[MAXN][MAXN] = {false}; // true if filled
bool vist[MAXN][MAXN] = {false}; // true if visited

vector<pair<int, int>> genNeighbors(int i, int j) {
    vector<pair<int, int>> out;

    if (i > 0) {
        out.push_back(make_pair(i - 1, j));
    }
    if (j > 0) {
        out.push_back(make_pair(i, j - 1));
    }
    if (j < MAXN) {
        out.push_back(make_pair(i, j + 1));
    }
    if (i < MAXN) {
        out.push_back(make_pair(i + 1, j));
    }

    return out;
}

void floodfill(int i, int j, bool n) {
    if (vist[i][j] || !grid[i][j]) {
        return;
    }
    vist[i][j] = true;
    if (n) {
        cc_count++;
    }

    for (auto p : genNeighbors(i, j)) {
        int x = p.first, y = p.second;
        floodfill(x, y, false);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    char c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            grid[i][j] = (c == '.' ? true : false);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j]) {
                continue;
            }

            floodfill(i, j, true);
        }
    }

    cout << cc_count << endl;
}
