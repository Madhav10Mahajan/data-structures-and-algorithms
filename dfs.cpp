void dfs(int start, unordered_map<int, vector<int>>&ourmap, unordered_map<int, bool>&visited) {
	visited[start] = true;
	vector<int> temp = ourmap[start];
	for (int i = 0; i < temp.size(); i++) {
		if (visited[temp[i]] != true) {
			dfs(temp[i], ourmap, visited);
		}
	}
}

