#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[2];

public:
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node *node) {
        links[bit] = node;
    }
    Node *get(int bit) {
        return links[bit];
    }
};
class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

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

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }

    Trie trie;
    for (auto it : nums) {
        trie.insert(it);
    }

    int maxi = 0;
    rep(5) {
        for (auto it : nums) {
            maxi = max(maxi, trie.getMax(it));
        }
        nums.pb(maxi);
    }
    cout << maxi << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
