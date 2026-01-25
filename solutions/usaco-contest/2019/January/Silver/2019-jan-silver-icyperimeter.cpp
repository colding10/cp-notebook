#include <vector>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

#define MAXN 1005

int id = 1;
bool grid[MAXN][MAXN] = {false}; // true is fillled
int cc[MAXN][MAXN] = {0};
map<int, pair<int, int>> vals; // id : area, perim

vector<pair<int, int>> genNeighbors(int i, int j) {
	vector<pair<int, int>> out;
	
	if (i > 0) {
		out.push_back(make_pair(i-1, j));	
	}
	if (j > 0) {
		out.push_back(make_pair(i, j-1));
	}
	if (j < MAXN) {
		out.push_back(make_pair(i, j+1));
	}
	if (i < MAXN) {
		out.push_back(make_pair(i+1, j));
	}

	return out;
}

void floodfill(int i, int j, bool n) {
	if (!grid[i][j]) {
		if (!n) {
			vals[id].second++;
		}
		
		return;
	} else if (cc[i][j] != 0) {
		return;
	} // return if already visited or is empty

	if (n) {
		id++;
		vals[id] = {0, 0};
	}

	cc[i][j] = id;
	vals[id].first++;
	
	for (auto p : genNeighbors(i, j)) {
		int x = p.first, y = p.second;

		floodfill(x, y, false);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	
	int N;
	char c;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c;
			grid[i][j] = (c == '#' ? true : false);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!grid[i][j]) {
				continue;
			}
			floodfill(i, j, true);
		}
	}

	int bestarea = 0;
	int bestprim = 0;
	
	for (auto p : vals) {
		int area = p.second.first;
		int prim = p.second.second;
		
		if (area > bestarea) {
			bestarea = area;
			bestprim = prim;
		}
		if (area == bestarea && prim < bestprim) {
			bestarea = area;
			bestprim = prim;
		}
	}

	cout << bestarea << " " << bestprim << endl;
}
