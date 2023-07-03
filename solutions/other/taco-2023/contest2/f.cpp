#include <iostream>
#include <unordered_map>
using namespace std;

int n, x;


void recurse(int a, int val, string s) {
    if (a > n) {
        if (val == x) {
            cout << s.substr(0, s.length() - 1) << endl;
            exit(0);
        }
        return;
    }

    // Perform recursive calls
    recurse(a+1, val+a, s + to_string(a) + "+");
    recurse(a+1, val-a, s + to_string(a) + "-");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;

    // Start the recursive function
    recurse(0, 0, "");

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
