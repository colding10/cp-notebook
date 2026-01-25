#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int a, int b) : x(a), y(b) {}
    bool operator<(const Point &other) {
        if (x < other.x) {
            return true;
        }
        if (y < other.y) {
            return true;
        }

        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Point> peaks;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        peaks.push_back(Point(a, b));
    }

    sort(peaks.begin(), peaks.end());
}
