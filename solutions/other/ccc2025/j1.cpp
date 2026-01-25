#include <iostream>

using namespace std;

int main() {
    long long n, c, p;
    cin >> n >> c >> p;
    if (n <= c*p) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
