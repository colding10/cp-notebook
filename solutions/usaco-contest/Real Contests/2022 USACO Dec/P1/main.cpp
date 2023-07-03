#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    pair<int, int> best {0, RLIM_INFINITY};

    for (int i = 0; i < n; i++) {
        int value = cows[i];

        int result = value * (n - i)

        if (result == best.first
    }
}