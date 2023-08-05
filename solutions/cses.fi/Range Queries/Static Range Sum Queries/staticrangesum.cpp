#include <iostream>
#include <vector>

using namespace std;

#define MAXN 200000
#define MAXQ 200000

long long int arr[MAXN];
long long int prefix[MAXN];

int main() {
    int n, q;
    cin >> n >> q;

    prefix[0] = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }
}
