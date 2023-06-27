void bfs(int start, unordered_map<int, vector<int>>&ourmap, unordered_map<int, bool>&visited) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (q.size() != 0) {
		int front = q.front();
		q.pop();
		vector<int> temp = ourmap[front];
		for (int i = 0; i < temp.size(); i++) {
			if (visited[temp[i]] != true) {
				visited[temp[i]] = true;
				q.push(temp[i]);
			}
		}
	}
}
