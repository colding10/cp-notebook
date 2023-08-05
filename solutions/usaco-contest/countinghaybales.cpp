#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXN 100010
#define MAXQ 100010

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("haybales");

    int n, q;
    cin >> n >> q;

    vector<int> nums;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << upper_bound(nums.begin(), nums.end(), b) -
                    lower_bound(nums.begin(), nums.end(), a)
             << endl;
    }
}
