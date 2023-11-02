bool bellmanford(vector<pair<pair<int, int>, int>>&edges, vector<int>&distance) {

	int n = distance.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < edges.size(); j++) {
			pair<pair<int, int>, int> p = edges[j];
			int a = p.first.first;
			int b = p.first.second;
			int w = p.second;
			if (distance[a] != 1e9 && distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		pair<pair<int, int>, int> p = edges[j];
		int a = p.first.first;
		int b = p.first.second;
		int w = p.second;
		if (distance[a] != 1e9 && distance[a] + w < distance[b]) {
			return false;
		}
	}
	return true;
}
void solve() {

	int n, m;
	cin >> n >> m;
	int start;
	cin >> start;
	vector<pair<pair<int, int>, int>> edges(m);
	vector<int> distance(n + 1, 1e9);
	distance[start] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {{a, b}, w};
	}
	bool ans = bellmanford(edges, distance);
	if (ans == true) {
		for (int i = 0; i <= n; i++) {
			cout << distance[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Negative Cycle" << endl;

	}

}
