#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int solveRecursion(int X, int Y, int M, int m_amount) {
    if (M - m_amount < X && M - m_amount - Y < 0) {
        return m_amount;
    } else {
        if (M - m_amount - X < 0) {
            return solveRecursion(X, Y, M, m_amount + Y);
        } else if (M - m_amount - Y < 0) {
            return solveRecursion(X, Y, M, m_amount + X);
        } else {
            return max(solveRecursion(X, Y, M, m_amount + X),
                    solveRecursion(X, Y, M, m_amount + Y));
        }
    }
}

int solve(int buck1, int buck2, int buck3) {
    int ans = 0;

    for (int i = 0; i <= 1000; i++) {
        if ((buck1 * i) > buck3) {
            break;
        } 
        for (int j = 0; j <= 1000; j++) {
            int current = (buck1 * i) + (buck2 * j);
            if (current > buck3) {
                break;
            }
            ans = max(ans, current);
        }
    }

    return ans;
}

int main() {
    setIO("pails");

    int X, Y, M;
    vi maximums;

    cin >> X >> Y >> M;

    cout << solve(X, Y, M) << "\n";
}