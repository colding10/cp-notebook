#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl "\n"

using std::cin;
using std::cout;
using std::string;
using std::vector;

typedef std::pair<int, int> Location;

#define DOWN 0
#define RIGHT 1

class Cow {
   public:
    int startX;
    int startY;

    int cost;
    vector<Location> traveled;

    Cow(int sX, int sY, int *graph, int n) {
        this->startX = sX;
        this->startY = sY;

        while (sX != n && sY != n) {
            this->traveled.push_back({sX, sY});

            unsigned int direction = *((graph + sX * n) + sY);
            if (direction == DOWN) {
                sY++;
            } else {
                sX++;
            }
        }

        this->cost = *((graph + sX * n) + sY);
    }
};

int main() {
    int n, t;

    cin >> n;

    int graph[n + 1][n + 1];

    string directions;
    
    int cx;

    for (int i = 0; i < n; i++) {
        cin >> directions >> cx;
        for (int j = 0; j < n; j++) {
            graph[i][j] = directions[j] == 'D' ? DOWN : RIGHT;
        }
        graph[i][n] = cx;
    }

    for (int i = 0; i < n; i++) {
        cin >> graph[n][i];
    }
    graph[n][n] = 0;

    cin >> t;

    int cost = 0;
    vector<Cow> cows;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n + 1 && j == n + 1) {
                continue;
            }

            Cow c(i, j, (int *)graph, n);
            cost += c.cost;
            cows.push_back(c);
        }
    }

    int x, y;
    int delta;
    int prev, after;

    for (int i = 0; i < 8; i++) {
        cin >> x >> y;
        x--;
        y--;

        graph[x][y] = (graph[x][y] == RIGHT ? DOWN : RIGHT);
        Location coord = {x, y};

        cout << cost << endl;
        delta = 0;

        vector<Cow> new_cows;

        for (Cow c : cows) {
            if (std::find(c.traveled.begin(), c.traveled.end(), coord) != c.traveled.end()) {
                prev = c.cost;
                c = Cow(c.startX, c.startY, (int *) graph, n);
                after = c.cost;

                delta += after - prev;
            }

            new_cows.push_back(c);
        }

        cows = new_cows;

        cost += delta;
    }

    cout << cost << endl;
}