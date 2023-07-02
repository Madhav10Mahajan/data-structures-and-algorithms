void toposort(int start, unordered_map<int, vector<int>>&ourmap, unordered_map<int, bool>&visited, stack<int>&s) {

	visited[start] = true;
	vector<int> temp = ourmap[start];
	for (int i = 0; i < temp.size(); i++) {
		if (visited[temp[i]] != true) {
			toposort(temp[i], ourmap, visited, s);
		}
	}
	s.push(start);
}
void solve() {

	int n, m;
	cin >> n >> m;
	unordered_map<int, vector<int>> ourmap;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ourmap[a].push_back(b);
	}
	stack<int> s;
	unordered_map<int, bool> visited(false);
	toposort(1, ourmap, visited, s);
	while (s.size() != 0) {
		cout << s.top() << endl;
		s.pop();
	}
}

