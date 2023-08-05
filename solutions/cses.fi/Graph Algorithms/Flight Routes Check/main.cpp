#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

bool visited[100000000];
vector<int> graph[100000000];

void dfs(int node, int target, int prev) {
    if (visited[node]) {
        return;
    } else if (visited[target]) {
        return;
    }
    visited[node] = true;

    if (prev != -1) {
        graph[prev].push_back(node);
    }

    for (int n : graph[node]) {
        dfs(n, target, node);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) {
                continue;
            }

            for (int i = 0; i <= n; i++) {
                visited[i] = false;
            }
            dfs(a, b, -1);
            if (visited[b] == false) {
                cout << "NO\n" << a << " " << b << "\n";
                return 0;
            }
        }
    }

    cout << "YES"
         << "\n";
    return 0;
}
