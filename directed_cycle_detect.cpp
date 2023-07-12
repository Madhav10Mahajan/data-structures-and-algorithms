bool dfs(int start, unordered_map<int, vector<int>>&ourmap, unordered_map<int, bool>&visited, unordered_map<int, boo>&dfsvisited) {

	visited[start] = true;
	dfsvisited[start] = true;
	vector<int> temp = ourmap[start];
	for (int i = 0; i < temp.size(); i++) {

		if (visited[temp[i]] == true && dfsvisited[temp[i]] == true) {
			return true;
		}
		else if (visited[temp[i]] != true) {
			bool ans = dfs(temp[i], ourmap, visited, dfsvisited);
			if (ans == true) {
				return true;
			}
		}
	}
	dfsvisited[start] = false;
	return false;
}
void solve() {

	int n, m;
	cin >> n > m;
	unordered_map<int, vector<int>> ourmap;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ourmap[a].push_back(b);
		ourmap[b].push_back(a);
	}
	unordered_map<int, bool> visited(false);
	unordered_map<int, bool> dfsvisited(false);
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] != true) {
			bool ans = dfs(i, ourmap, visited, dfsvisited);
			if (ans == true) {
				flag = 1;
				break;
			}
		}
	}
	cout << flag << endl;
}

