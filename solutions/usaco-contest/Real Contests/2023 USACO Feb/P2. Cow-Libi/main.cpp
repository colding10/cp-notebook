#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y, t;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool can_reach_all(Point cow, vector<Point> grazings) {
    grazings.push_back(cow);
    sort(grazings.begin(), grazings.end(), [](const Point& a, const Point& b) {
        return a.t < b.t;
    });

    cow = grazings[0];
    
    for (int i = 1; i < grazings.size(); i++) {
        Point g = grazings[i];

        long long dist = distance(cow, g);
        long long time = g.t - cow.t;
        if (time < dist) { // can't make it, not enough time
            return false;
        }
        cow = g;
    }
    return true;
}

int main() {
    int G, N;
    cin >> G >> N;

    vector<Point> grazings(G);
    for (int i = 0; i < G; i++) {
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }
    sort(grazings.begin(), grazings.end(), [](const Point& a, const Point& b) {
        return a.t < b.t;
    });

    int count = 0;
    for (int i = 0; i < N; i++) {
        Point cow;
        cin >> cow.x >> cow.y >> cow.t;
        if (can_reach_all(cow, grazings)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
