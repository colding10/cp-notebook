#include <iostream>
#include <vector>

using namespace std;

#define MAXN 105

vector<pair<int, int>> genNeighbors(int i, int j, int n) { 
    vector<pair<int, int>> neighbors; 
    if (i > 0) neighbors.push_back(make_pair(i - 1, j)); 
    if (j > 0) neighbors.push_back(make_pair(i, j - 1)); 
    if (i < n-1) neighbors.push_back(make_pair(i + 1, j)); 
    if (j < n-1) neighbors.push_back(make_pair(i, j + 1)); 
    return neighbors;
}


bool grid[MAXN][MAXN] = {false}; // true for light is on
bool visited[MAXN][MAXN] = {false};
vector<pair<int, int>> switches[MAXN][MAXN];
long long c = 1;


void floodfill(int i, int j, int n) {
    if (visited[i][j]) {
        return;
    }
    if (!grid[i][j]) { // lights off, too scary
        return;
    }

    visited[i][j] = true;
    
    for (auto p : switches[i][j]) {
        if (!grid[p.first][p.second]) {
       		 grid[p.first][p.second] = true;
        	c++;
            for (auto a : genNeighbors(p.first, p.second, n)) {
                if (grid[a.first][a.second]) {
                    floodfill(p.first, p.second, n);
                }
            }
            
        }
    }

    for (auto p : genNeighbors(i, j, n)) {
        floodfill(p.first, p.second, n);
    }
}

int main() {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	
	grid[1][1] = true;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		// cout << "added {" << c << ", " << d << "} at switches[" << a << "][" << b << "]\n";
		switches[a][b].push_back(make_pair(c, d));
	}

	floodfill(1, 1, n);

	cout << c << endl;
}
