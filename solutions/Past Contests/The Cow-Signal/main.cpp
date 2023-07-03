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