#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

ll power(ll base, ll e, ll M = MOD) {
    assert(e >= 0);

    ll result = 1;
    base %= M;

    while (e) {
        if (e & 1) {
            result = (result * base) % M;
        }
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}
