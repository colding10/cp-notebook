#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define MAXN 1500

vector<int> adj[MAXN];
bool visited[MAXN] = {false};
map<int, int> dists;

void dfs(int node, int dist) {
  if (visited[node]) {
    return;
  }

  dists[node] = dist;
  visited[node] = true;
  for (int n : adj[node]) {
    dfs(n, dist + 1);
  }
}

int main() {
  int b, n;
  cin >> b >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(b, 0);
//   cout << "OUTPUT" << endl;
//   for (auto it = dists.cbegin(); it != dists.cend(); ++it) {
//     std::cout << it->first << " " << it->second << "\n";
//   }

  int best_node = -1;
  int best_val = -1;

  for (auto p : dists) {
    if (p.second > best_val) {
      best_node = p.first;
      best_val = p.second;
    }
    if (p.second == best_val && p.first > best_node) {
      best_node = p.first;
    }
  }

  cout << best_node << endl;

  return 0;
}