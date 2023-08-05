#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> nums;

int main() {
    cin >> n >> x;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    for (int a = 0; a < n; a++) {
        int l = 0;
        int r = n - 1;

        while (l != r) {
            int s = nums[a].first + nums[l].first + nums[r].first;

            if (l != a && r != a && s == x) {
                cout << nums[a].second << " " << nums[l].second << " "
                     << nums[r].second << endl;
                return 0;
            }

            if (s < x) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
