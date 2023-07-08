#include <bits/stdc++.h>

template <class T> bool ckmin(T &a, T &b) {
    bool B = a > b;
    a = std::min(a, b);
    return B;
}
template <class T> bool ckmax(T &a, T &b) {
    bool B = a < b;
    a = std::max(a, b);
    return B;
}
