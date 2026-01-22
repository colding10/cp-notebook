// ---
// Mo's Algorithm - Offline range queries in O((N + Q) * sqrt(N))
// Use when: no updates, can add/remove elements in O(1) or O(log n)

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int b1 = l / block_size, b2 = other.l / block_size;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r > other.r) : (r < other.r);
    }
};

// Global state for current window
// int current_answer;
// vector<int> cnt;

void add(int idx) {
    // Add element at index idx to current window
    // Example: cnt[a[idx]]++; if (cnt[a[idx]] == 1) current_answer++;
}

void remove(int idx) {
    // Remove element at index idx from current window
    // Example: cnt[a[idx]]--; if (cnt[a[idx]] == 0) current_answer--;
}

vector<int> mo_algorithm(vector<Query>& queries, int n) {
    block_size = max(1, (int)sqrt(n));
    sort(queries.begin(), queries.end());

    vector<int> answers(queries.size());
    int cur_l = 0, cur_r = -1;

    for (auto& q : queries) {
        while (cur_r < q.r) add(++cur_r);
        while (cur_l > q.l) add(--cur_l);
        while (cur_r > q.r) remove(cur_r--);
        while (cur_l < q.l) remove(cur_l++);

        // answers[q.idx] = current_answer;
    }

    return answers;
}

/*
Usage:
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--;  // 0-indexed
        queries[i].idx = i;
    }

    auto answers = mo_algorithm(queries, n);
*/
