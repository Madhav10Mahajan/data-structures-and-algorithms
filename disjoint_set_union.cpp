int findparent(int node, vector<int>&parent) {

	if (parent[node] == node) {
		return node;
	}
	return parent[node] = findparent(parent[node], parent);
}
void unionbyrank(int u, int v, vector<int>&rank, vector<int>&parent) {

	int pu = findparent(u, parent);
	int pv = findparent(v, parent);
	if (pu == pv) {
		return;
	}
	if (rank[pu] > rank[pv]) {
		parent[pv] = pu;
	}
	else if (rank[pv] > rank[pu]) {
		parent[pu] = pv;
	}
	else {
		parent[pv] = pu;
		rank[pu]++;
	}
}
void solve() {

	vector<int> rank(n + 1, 0);
	vector<int> parent(n + 1);
	for (int i - 0; i < n + 1; i++) {
		parent[i] = i;
	}

}
