#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll, ll>;
using pll = pair<ll, ll>;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

ll n;

int MOD = 1e9 + 7;

int power(long long base, int e, int M = MOD) {
    long long result = 1;
    base %= M;
    while (e) {
        if (e & 1) result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

ll intLog(ll base, ll x) {
    ll res = 0;
    while (x >= base) {
        x /= base;
        res++;
    }
    return res;
}

const int tab64[64] = {63, 0,  58, 1,  59, 47, 53, 2,  60, 39, 48, 27, 54,
                       33, 42, 3,  61, 51, 37, 40, 49, 18, 28, 20, 55, 30,
                       34, 11, 43, 14, 22, 4,  62, 57, 46, 52, 38, 26, 32,
                       41, 50, 36, 17, 19, 29, 10, 13, 21, 56, 45, 25, 31,
                       35, 16, 9,  12, 44, 24, 15, 8,  23, 7,  6,  5};

int log2_64(uint64_t value) {
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((uint64_t)((value - (value >> 1)) * 0x07EDD5E59A4E28C2)) >>
                 58];
}
#include <cmath>
#include <cstdint>
#include <cstring>

float __int_as_float(int32_t a) {
    float r;
    memcpy(&r, &a, sizeof r);
    return r;
}
int32_t __float_as_int(float a) {
    int32_t r;
    memcpy(&r, &a, sizeof r);
    return r;
}

/* compute natural logarithm, maximum error 0.85089 ulps */
float my_logf(float a) {
    float i, m, r, s, t;
    int e;

#if PORTABLE
    m = frexpf(a, &e);
    if (m < 0.666666667f) {
        m = m + m;
        e = e - 1;
    }
    i = (float)e;
#else  // PORTABLE
    i = 0.0f;
    if (a < 1.175494351e-38f) { // 0x1.0p-126
        a = a * 8388608.0f;     // 0x1.0p+23
        i = -23.0f;
    }
    e = (__float_as_int(a) - __float_as_int(0.666666667f)) & 0xff800000;
    m = __int_as_float(__float_as_int(a) - e);
    i = fmaf((float)e, 1.19209290e-7f, i); // 0x1.0p-23
#endif // PORTABLE
    /* m in [2/3, 4/3] */
    m = m - 1.0f;
    s = m * m;
    /* Compute log1p(m) for m in [-1/3, 1/3] */
    r = -0.130310059f;             // -0x1.0ae000p-3
    t = 0.140869141f;              //  0x1.208000p-3
    r = fmaf(r, s, -0.121483512f); // -0x1.f198b2p-4
    t = fmaf(t, s, 0.139814854f);  //  0x1.1e5740p-3
    r = fmaf(r, s, -0.166846126f); // -0x1.55b36cp-3
    t = fmaf(t, s, 0.200120345f);  //  0x1.99d8b2p-3
    r = fmaf(r, s, -0.249996200f); // -0x1.fffe02p-3
    r = fmaf(t, m, r);
    r = fmaf(r, m, 0.333331972f);  //  0x1.5554fap-2
    r = fmaf(r, m, -0.500000000f); // -0x1.000000p-1
    r = fmaf(r, s, m);
    r = fmaf(i, 0.693147182f, r); //  0x1.62e430p-1 // log(2)
    if (!((a > 0.0f) && (a < INFINITY))) {
        r = a + a;                             // silence NaNs if necessary
        if (a < 0.0f) r = INFINITY - INFINITY; //  NaN
        if (a == 0.0f) r = -INFINITY;
    }
    return r;
}
bool verify(ll k) {
    ll exponent = (my_logf(n * (k - 1) + 1) / my_logf(k)) - 1;
    ll sum = (power(k, exponent + 1) - 1) / (k - 1);
    return (sum == n && exponent > 1);
}

void solve() {
    ll n;
    cin >> n;
    for (ll k = 2; k * k <= n; k++) {
        ll vertices = 1 + (power(k, 2) - 1) / (k - 1);
        if (vertices == n) {
            cout << "YES" << endl;
            return;
        }
        if (vertices > n) break;
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
