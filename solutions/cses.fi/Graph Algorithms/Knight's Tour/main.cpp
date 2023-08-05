#include <iostream>
#include <vector>

using namespace std;

bool visited[8][8] = {{false}};
int grid[8][8];
int value = 1;

vector<pair<int, int>> genNeighbors(int i, int j) {
    vector<pair<int, int>> out;

    out.push_back(make_pair(i + 2, j + 1));
    out.push_back(make_pair(i + 1, j + 2));
    out.push_back(make_pair(i + 2, j - 1));
    out.push_back(make_pair(i + 1, j - 2));
    out.push_back(make_pair(i - 2, j + 1));
    out.push_back(make_pair(i - 1, j + 2));
    out.push_back(make_pair(i - 2, j - 1));
    out.push_back(make_pair(i - 1, j - 2));

    return out;
}

void recurse(int i, int j) {
    if (i < 0 || j < 0 || i >= 8 || j >= 8) {
        return;
    }

    if (visited[i][j]) {
        return;
    }

    visited[i][j] = true;
    grid[i][j] = value;
    value++;

    for (auto p : genNeighbors(i, j)) {
        recurse(p.first, p.second);
    }

    // Reset visited flag for backtracking
    visited[i][j] = false;
    value--;
}

int main() {
    int x, y;
    cin >> x >> y;
    recurse(y - 1, x - 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << (grid[i][j] < 10 ? " " : "") << grid[i][j]
                 << (j != 7 ? " " : "");
        }
        cout << endl;
    }

    return 0;
}
