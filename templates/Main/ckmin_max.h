template <class T> bool ckmin(T &a, T &b) {
    bool B = a > b;
    a = min(a, b);
    return B;
}
template <class T> bool ckmax(T &a, T &b) {
    bool B = a < b;
    a = max(a, b);
    return B;
}

