#include <iostream>

using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
setIO("sort");
	int x;
	cin >> x;
	cout << x-1 << endl;
}
