#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> books(n);
    for (ll i = 0; i < n; i++) {
        cin >> books[i];
    }

    ll longest_time = *max_element(books.begin(), books.end());
    ll total_time = accumulate(books.begin(), books.end(), 0ll);

    cout << max(total_time, longest_time * 2) << "\n";
}
