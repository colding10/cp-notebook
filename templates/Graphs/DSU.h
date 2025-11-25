struct DisjointSets {
	int n, connected_comps;
	vector<int> parents, sizes;

	DisjointSets(int n) : n(n), connected_comps(n) {
		parents = vector<int>(n);
		iota(begin(parents), end(parents), 0);
		sizes = vector<int>(n, 1);
	}

	int get(int x) {
		if (x == parents[x]) { return x; }
		return parents[x] = get(parents[x]);
	}

	bool unite(int x, int y) {
		int x_root = get(x);
		int y_root = get(y);

		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { std::swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		connected_comps--;

		return true;
	}

	bool connected(int x, int y) { return (get(x) == get(y)); }
};