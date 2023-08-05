#include <cmath>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long int a, b;
        cin >> a >> b;
        long long int out = pow(a, b);
        out %= MOD;

        cout << out << endl;
    }
}
