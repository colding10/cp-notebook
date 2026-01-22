#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// handle negative mod cuz c++ trolling
ll mod(ll a, ll m) { return ((a % m) + m) % m; }

ll query_pos(ll c, ll t) {
    if (c > t / 2) return c; // static zone

    ll pos = c;
    ll e = c;
    ll e_end = t / 2;
    if (t % 2 == 0) e_end--; // half an epoch (do the one extra step at end)

    while (e <= e_end) {
        ll size = e + 1;
        ll k = (pos >= 2) ? pos / 2 : 0; // batch k epochs together
        ll epochs_left = e_end - e + 1;

        if (k >= epochs_left) {
            pos -= 2 * epochs_left;
            break;
        }

        pos -= 2 * k;
        e += k;
        if (e > e_end) break;

        size = e + 1;
        pos = mod(pos - 2, size);
        e++;
    }

    if (t % 2 == 0) {
        ll size = t / 2 + 1;
        pos = mod(pos - 1, size);
    }

    return pos;
}

ll query_cow(ll x, ll t) {   // pretty much same as upper one in reverse
    if (x > t / 2) return x; // static zone

    ll p = x;
    ll e = t / 2;

    if (t % 2 == 0) {
        ll size = e + 1;
        p = (p + 1) % size;
        if (p >= e) return p;
        e--;
    }

    while (e >= 0) {
        ll size = e + 1;
        ll k = (e - p) / 3;

        if (k <= 0) {
            p = (p + 2) % size;
            if (p >= e) return p;
            e--;
        } else {
            if (k > e + 1) k = e + 1;
            p += 2 * k;
            e -= k;
            if (e < 0 || p >= e + 1) return p;
        }
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        ll a, t;
        cin >> type >> a >> t;
        if (type == 1) {
            cout << query_pos(a, t) << "\n";
        } else {
            cout << query_cow(a, t) << "\n";
        }
    }
    return 0;
}
// STOP LOOKING HERE AND LOOK AT THE PAPER
