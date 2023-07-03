#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<int> teams(N);
    for (int i = 0; i < N; i++) {
        int bitmask = 0;
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == 'H') {
                bitmask |= (1 << j);
            }
        }
        teams[i] = bitmask;
    }

    for (int i = 0; i < N; i++) {
        int max_diff = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int diff;

                diff = BitCount(teams[i] ^ teams[j]);

                max_diff = max(max_diff, diff);
            }
        }

        cout << max_diff << endl;
    }

    return 0;
}