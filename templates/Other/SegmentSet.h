#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Segment {
    int l, r;

    bool operator<(Segment const &other) const {
        return l < other.l;
    }

    int overlap(Segment const &o) const {
        return max(0, min(r, o.r) - max(l, o.l));
    }

    bool touch(Segment const &o) const {
        return overlap(o) || o.r == l || o.l == r;
    }

    Segment Union(Segment const o) const {
        return {min(l, o.l), max(r, o.r)};
    }

    friend ostream &operator<<(ostream &os, Segment const &s) {
        return os << "[" << s.l << ", " << s.r << "]";
    }

    friend istream &operator>>(istream &is, Segment &s) {
        return is >> s.l >> s.r;
    }
};

/**
 * Set containing segements
 * If two segments overlap or touch (depending on settings), they will be
 * replaced by their union.
 */
class DisjointSegmentSet {
public:
    DisjointSegmentSet(bool touching = true) : touching(touching) {}
    using It = set<Segment>::iterator;
    using ItRange = pair<It, It>;

    /**
     * add a segment to the set, union with overlapping/touching segments
     */
    void add_segment(Segment s) {
        auto [lit, rit] = get_overlapping_or_touching(s);
        for (It it = lit; it != rit; ++it) {
            auto &t = *it;
            s = s.Union(t);
        }
        segments.erase(lit, rit);
        segments.insert(s);
    }

    /**
     * remove a segment from the set, return the overlaps
     */
    vector<Segment> subtract(Segment s) {
        split(s.l);
        split(s.r);
        auto [lit, rit] = get_overlapping(s);
        vector<Segment> ret(lit, rit);
        segments.erase(lit, rit);
        return ret;
    }

    /**
     * Find a segment that contains x
     * In case of two segments touching at x, it will find the left one
     */
    It find_containing(int x) const {
        It lit = segments.lower_bound({x, 0});
        if (lit != segments.begin()) {
            --lit;
            if (lit->r < x)
                ++lit;
        }
        return lit;
    }

    friend ostream &operator<<(ostream &os,
                                    DisjointSegmentSet const &dss) {
        os << "DSS(";
        auto bit = dss.segments.begin();
        for (auto it = bit; it != dss.segments.end(); ++it) {
            if (it != bit)
                os << ", ";
            os << *it;
        }
        return os << ")";
    }

private:
    ItRange get_overlapping_or_touching(Segment const &s) const {
        // find smallest segment with l >= s.l
        auto lit = touching ? segments.lower_bound(s) : segments.upper_bound(s);
        // it's possible that there is one the left
        if (lit != segments.begin()) {
            --lit;
            if (touching && lit->r < s.l)
                ++lit;
            if (!touching && lit->r <= s.l)
                ++lit;
        }

        // find right boundary
        auto rit = touching ? segments.upper_bound({s.r, 0})
                   : segments.lower_bound({s.r, 0});

        return {lit, rit};
    }

    void split(int x) {
        auto it = find_containing(x);
        if (it == segments.end())
            return;
        auto s = *it;
        if (s.l < x && x < s.r) {
            segments.erase(it);
            auto s1 = s;
            s1.r = x;
            auto s2 = s;
            s2.l = x;
            segments.insert(s1);
            segments.insert(s2);
        }
    }

    bool touching;
    set<Segment> segments;
};
