#include <iostream>

using namespace std;

int main() {
    int d, e;
    cin >> d >> e;
    for (int i = 0; i < e; i++) {
        char t;
        cin >> t;
        int c;
        cin >> c;
        if (t == '+') {
            d += c;
        } else {
            d -= c;
        }
    }
    cout << d << endl;
}
