long long prims(unordered_map<int, vector<pair<int, int>>>&ourmap, unordered_map<int, bool>&visited) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
	minheap.push({0, 0});
	long long ans = 0;
	while (minheap.size() != 0) {

		pair<int, int> front = minheap.top();
		minheap.pop();
		int node = front.second;
		int w = front.first;
		if (visited[node] == true) {
			continue;
		}
		ans = ans + w;
		visited[node] = true;
		vector<pair<int, int>> temp = ourmap[node];
		for (int i = 0; i < temp.size(); i++) {

			int neighbour = temp[i].first;
			int w = temp[i].second;
			if (visited[neighbour] != true) {
				minheap.push({w, neighbour});
			}
		}
	}
	return ans;
}
void solve() {

	int n, m;
	cin >> n >> m;
	unordered_map<int, vector<pair<int, int>>> ourmap;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		ourmap[a].push_back({b, w});
		ourmap[b].push_back({a, w});
	}
	unordered_map<int, bool> visited(false);
	cout << prims(ourmap, visited) << endl;
}
