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

#define INT_SIZE 32

struct TrieNode {
    int value; // Only used in leaf nodes
    TrieNode *arr[2];
};

TrieNode *newNode() {
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(TrieNode *root, int pre_xor) {
    TrieNode *temp = root;

    for (int i = INT_SIZE - 1; i >= 0; i--) {
        bool val = pre_xor & (1 << i);

        if (temp->arr[val] == NULL) temp->arr[val] = newNode();

        temp = temp->arr[val];
    }

    temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor) {
    TrieNode *temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        // Find current bit in given prefix
        bool val = pre_xor & (1 << i);

        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp->arr[1 - val] != NULL) temp = temp->arr[1 - val];

        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor ^ (temp->value);
}

int maxSubarrayXOR(vector<int> &arr, int n) {
    TrieNode *root = newNode();
    insert(root, 0);

    // Initialize answer and xor of current prefix
    int result = INT_MIN, pre_xor = 0;

    // Traverse all input array element
    for (int i = 0; i < n; i++) {
        // update current prefix xor and insert it into Trie
        pre_xor = pre_xor ^ arr[i];
        insert(root, pre_xor);

        // Query for current prefix xor in Trie and update
        // result if required
        result = std::max(result, query(root, pre_xor));
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }

    cout << maxSubarrayXOR(nums, n) << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
