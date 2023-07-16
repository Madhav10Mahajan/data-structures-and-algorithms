void builsegtree(int index, int start, int end, vector<int>&arr, vector<int>&segmentree) {

	if (start == end) {
		segmenttree[start] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildsegtree(2 * index + 1, start, mid, arr, segmenttree);
	buildsegtree(2 * index + 2, mid + 1, end, arr, segmenttree);
	segmenttree[index] = min(segmenttree[2 * index + 1], segmenttree[2 * index + 2]);
}
int query(int index, int start, int end, int l, int r, vector<int>&segmentree) {


	if (l <= start && end <= r) {
		return segmentree[index];
	}
	int mid = (start + end) / 2;
	if (l >= start && r <= end) {

		int left = query(2 * index + 1, start, mid, l, r, segmentree);
		int right = query(2 * index + 2, mid + 1, end, l, r, segmentree);
		return min(left, right);
	}
	return 1e9;
}
void update(int index, int start, int end, int node, int val) {

	if (start == end) {
		segmenttree[node] = segmentree[node] + val;
		return;
	}
	int mid = (start + end) / 2;
	if (node >= mid && node <= end) {
		update(2 * index + 2, mid + 1, end, node, val);
	}
	else {
		update(2 * index + 1, start, mid, node, val);
	}
	segmenttree[index] = min(segmenttree[2 * index + 1], segmenttree[2 * index + 2]);
}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int q;
	cin >> q;
	vector<int> segmenttree(4 * n);
	buildsegtree(0, 0, n - 1, arr, segmenttree);
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << query(0, 0, n - 1, l, r, segmenttree) << endl;
	}
}
