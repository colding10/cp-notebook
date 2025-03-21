#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'
#define lli long long int
#define li long int
#define ld long double
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    
    cin >> N;
    vii arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		arr[i] = make_pair(A, B);
	}

    sort(arr.begin(), arr.end());

    lli total = 0, curr = 0;
	for (auto ele : arr)
	{
		curr += ele.first;
		total += ele.second - curr;
	}
    cout << total;

    return 0;
}