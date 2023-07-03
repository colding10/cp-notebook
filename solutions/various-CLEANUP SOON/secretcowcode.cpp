#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    string s;
    long long n;

    cin >> s >> n;

    long long len_s = s.length();
    long long needed_reps = ceil(log2(n/len_s + 1));

    string code = s;
    while (code.length() < n) {
        long long len_code = code.length();
        if (len_code * 2 <= n) {
            code += code;
        } else {
            long long len_tail = len_code - n;
            if (len_tail > 0) {
                code.erase(n, len_tail);
            }
            break;
        }
    }

    cout << code[n - 1] << endl;

    return 0;
}
