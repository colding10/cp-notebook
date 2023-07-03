#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int ans = 0;
    int start = 0;
    while (start < n) {
        int end = start + 1;
        while (end < n && heights[end] > 0) {
            ++end;
        }
        int last_non_zero = lower_bound(heights.begin() + start, heights.begin() + end, 1, greater<int>()) - heights.begin() - 1;
        int height = *min_element(heights.begin() + start, heights.begin() + last_non_zero + 1);
        ans += height;
        start = last_non_zero + 1;
    }
    cout << ans << endl;
    return 0;
}
