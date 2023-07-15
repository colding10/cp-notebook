#include <bits/stdc++.h>
using namespace std;

inline namespace FileIO {
inline void setIn(const string &s) {
    freopen(s.c_str(), "r", stdin);
}
inline void setOut(const string &s) {
    freopen(s.c_str(), "w", stdout);
}
inline void setIO(const string &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (int((s).size()))
        setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

inline namespace Helpers {
// is iterable
template <class T, class = void> struct is_iterable : false_type {};
template <class T>
struct is_iterable<
T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
: true_type {};
template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;

// is readable
template <class T, class = void> struct is_readable : false_type {};
template <class T>
struct is_readable<T, typename std::enable_if_t<is_same_v<
decltype(cin >> declval<T &>()), istream &>>>
: true_type {};
template <class T> constexpr bool is_readable_v = is_readable<T>::value;

// is printable
template <class T, class = void> struct is_printable : false_type {};
template <class T>
struct is_printable<T, typename std::enable_if_t<is_same_v<
decltype(cout << declval<T>()), ostream &>>>
: true_type {};
template <class T> constexpr bool is_printable_v = is_printable<T>::value;
} // namespace Helpers

inline namespace Input {
template <class T>
constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
template <class T, class... U> void re(T &t, U &...u);
template <class T, class U> void re(pair<T, U> &p); // pairs

// re: read
template <class T> typename enable_if<is_readable_v<T>, void>::type re(T &x) {
    cin >> x;
} // default
template <class T> void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
template <class T>
typename enable_if<needs_input_v<T>, void>::type
re(T &i); // ex. vectors, arrays
template <class T, class U> void re(pair<T, U> &p) {
    re(p.f, p.s);
}
template <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i) {
    for (auto &x : i)
        re(x);
}
template <class T, class... U> void re(T &t, U &...u) {
    re(t);
    re(u...);
} // read multiple

// rv: resize and read vectors
inline void rv(size_t) {}
template <class T, class... U> void rv(size_t N, vector<T> &t, U &...u);
template <class... U> void rv(size_t, size_t N2, U &...u);
template <class T, class... U> void rv(size_t N, vector<T> &t, U &...u) {
    t.resize(N);
    re(t);
    rv(N, u...);
}
template <class... U> void rv(size_t, size_t N2, U &...u) {
    rv(N2, u...);
}

// dumb shortcuts to read in ints
inline void decrement() {} // subtract one from each
template <class T, class... U> void decrement(T &t, U &...u) {
    --t;
    decrement(u...);
}
#define ints(...)                                                              \
  int __VA_ARGS__;                                                             \
  re(__VA_ARGS__);
#define int1(...)                                                              \
  ints(__VA_ARGS__);                                                           \
  decrement(__VA_ARGS__);
} // namespace Input
