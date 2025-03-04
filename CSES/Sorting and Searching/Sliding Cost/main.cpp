#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int solve(vector<int>& numbers) {
    int target_length = numbers[numbers.size() / 2];
    int total = 0;
    for (int length : numbers) {
        total += abs(length - target_length);
    }
    return total;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> window = {0, k};

    for (int i = 0; i < n - k + 1; i++) {
        vector<int> numwindow(nums.begin() + window[0], nums.begin() + window[1]);
        cout << solve(numwindow) << " ";
        window[0]++;
        window[1]++;
    }

    cout << endl;
    return 0;
}
