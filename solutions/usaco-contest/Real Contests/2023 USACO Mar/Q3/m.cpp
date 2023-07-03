#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    cin >> t;
    int n = t.length();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        if (t.substr(i-6, 7) == "bessie") {
            p[i] = p[i-7] + 1;
        } else {
            p[i] = p[i-1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (t[j] == 'b' || t[j] == 'e' || t[j] == 's' || t[j] == 'i') {
                if (t.substr(j, 6) == "bessie") {
                    cnt++;
                }
            }
            ans += cnt * p[i];
        }
    }
    cout << ans << endl;
    return 0;
}
