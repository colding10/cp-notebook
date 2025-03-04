#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--; // convert to 0-indexed
        a[i] = j;

        // build priority queue of cows
        priority_queue<pair<int, int> > pq; // (milk, index)
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(a[i], i));
        }

        // unhook cows in order and calculate T
        long long T = 0;
        for (int i = 1; i <= n; i++) {
            auto cow = pq.top();
            pq.pop();
            T += (long long) i * cow.first;
            if (cow.second == i-1) {
                // skip this cow since its milk production value was updated
                i--;
            }
        }

        cout << T << endl;
    }
    return 0;
}
