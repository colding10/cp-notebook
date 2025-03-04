#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i = n; i < n + m; i++) {
        ans = (ans * i) % MOD;
        ans = (ans * pow(i - n + 1, MOD - 2)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
