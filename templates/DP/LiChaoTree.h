#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ---

struct Line {
    ll k, d;

    ll eval(int x) { return k * x + d; }
};

class LiChaoTree {
  public:
    LiChaoTree(int n) : n(n) {
        inf = {0LL, numeric_limits<ll>::max() / 2};
        lines.resize(4 * n);
        reset();
    }

    void reset() { fill(lines.begin(), lines.end(), inf); }

    void add_line(Line new_line, int id = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;

        int m = (l + r) / 2;
        bool left = new_line.eval(l) < lines[id].eval(l);
        bool middle = new_line.eval(m) < lines[id].eval(m);
        if (middle) swap(lines[id], new_line);

        if (r - l == 1) return;

        if (left != middle)
            add_line(new_line, id << 1, l, m);
        else
            add_line(new_line, id << 1 | 1, m, r);
    }

    ll get_minimum(int x, int id = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;

        ll seg_value = lines[id].eval(x);
        if (r - l == 1) return seg_value;

        int m = (l + r) / 2;
        if (x < m)
            return min(seg_value, get_minimum(x, id << 1, l, m));
        else
            return min(seg_value, get_minimum(x, id << 1 | 1, m, r));
    }

    int n;
    vector<Line> lines;
    Line inf;
};
