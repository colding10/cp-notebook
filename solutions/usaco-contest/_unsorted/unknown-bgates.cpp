#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;
    Point(int xIn, int yIn) : x(xIn), y(yIn) {}
};

int main() {
    ifstream fin("gates.in");
    ofstream fout("gates.out");

    int n;
    fin >> n;
    fin.get();

    string s;
    getline(fin, s);

    int currX = 1002;
    int currY = 1002;
    bool isFence[2005][2005] = {{false}};
    isFence[currX][currY] = true;

    for (int i = 0; i < s.length(); i++) {
        int dirX = 0, dirY = 0;
        if (s[i] == 'N') {
            dirX = -1;
        } else if (s[i] == 'S') {
            dirX = 1;
        } else if (s[i] == 'W') {
            dirY = -1;
        } else {
            dirY = 1;
        }
        for (int a = 0; a < 2; a++) {
            currX += dirX;
            currY += dirY;
            isFence[currX][currY] = true;
        }
    }

    int ret = -1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 2005; i++) {
        for (int j = 0; j < 2005; j++) {
            if (isFence[i][j]) {
                continue;
            }
            ret++;
            queue<Point> q;
            q.push(Point(i, j));
            isFence[i][j] = true;

            while (!q.empty()) {
                Point curr = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = curr.x + dx[k];
                    int ny = curr.y + dy[k];
                    if (nx >= 0 && nx < 2005 && ny >= 0 && ny < 2005 &&
                        !isFence[nx][ny]) {
                        isFence[nx][ny] = true;
                        q.push(Point(nx, ny));
                    }
                }
            }
        }
    }

    fout << ret << endl;
    return 0;
}
