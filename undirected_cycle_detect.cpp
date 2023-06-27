bool iscycle(int start, unordered_map<int, vector<int>>&ourmap, unordered_map<int, bool>&visited, unordered_map<int, int> &parent, int &startnode, int&endnode) {
	visited[start] = true;
	vector<int> temp = ourmap[start];
	for (int i = 0; i < temp.size(); i++) {

		if (visited[temp[i]] == true && temp[i] != parent[start]) {
			startnode = temp[i];
			endnode = start;
			return true;
		}
		else if (visited[temp[i]] != true) {
			parent[temp[i]] = start;
			bool ans = iscycle(temp[i], ourmap, visited, parent, startnode, endnode);
			if (ans == true) {
				return true;
			}
		}
	}
	return false;
}
