void buildtree(int index, int start, int end, vector<ll>&a, vector<ll>&segtree) {

	if (start == end) {
		segtree[index] = a[start];
		return;
	}
	int mid = (start + end) / 2;
	buildtree(2 * index + 1, start, mid, a, segtree);
	buildtree(2 * index + 2, mid + 1, end, a, segtree);
	segtree[index] = max(segtree[2 * index + 1], segtree[2 * index + 2]);
}
ll query(int index, int start, int end, int l, int r, vector<ll>&segtree) {

	if (start >= l && end <= r) {
		return segtree[index];
	}
	if (start > r || end < l) {
		return -1e9;
	}
	int mid = (start + end) / 2;
	ll leftans = query(2 * index + 1, start, mid, l, r, segtree);
	ll rightans = query(2 * index + 2, mid + 1, end, l, r, segtree);
	return max(leftans, rightans);

}

void solve() {

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> segtree(4 * n);
	buildtree(0, 0, n - 1, a, segtree);
	debug(a);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << query(0, 0, n - 1, l, r, segtree) << endl;;
	}
}
