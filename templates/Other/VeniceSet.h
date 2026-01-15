#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T> struct VeniceSet {
    multiset<T> s;
    T water_level = 0;

    void add(T v) { s.insert(v + water_level); }

    void remove(T v) { s.erase(s.find(v + water_level)); }

    void decrease_all(T v) { water_level += v; }

    T min() const { return *s.begin() - water_level; }

    int size() const { return s.size(); }
};
