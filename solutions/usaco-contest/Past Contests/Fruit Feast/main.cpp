#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool dp_water[5000001];
bool dp_drunk[5000001];

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b;
    cin >> t >> a >> b;

    dp_water[0] = true;
    for (int i = 1; i <= t; i++) {
        if (i - a >= 0) {
            dp_water[i] = dp_water[i] || dp_water[i - a];
        }
        if (i - b >= 0) {
            dp_water[i] = dp_water[i] || dp_water[i - b];
        }

        if (dp_water[i]) {
            dp_drunk[i / 2] = true;
        }
    }


    for (int i = 1; i <= t; i++) {
        if (i - a >= 0) {
            dp_drunk[i] = dp_drunk[i] || dp_drunk[i - a];
        }
        if (i - b >= 0) {
            dp_drunk[i] = dp_drunk[i] || dp_drunk[i - b];
        }

    }

    int drunk_highest = t;
    while (!dp_drunk[drunk_highest]) {
        drunk_highest--;
    }
    int water_highest = t;
    while (!dp_water[water_highest]) {
        water_highest--;
    }

    int highest = max(water_highest, drunk_highest);
    
    cout << highest << endl;
}
