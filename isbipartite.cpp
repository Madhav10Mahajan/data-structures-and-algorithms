bool isbipartite(int start, unordered_map<int, vector<int>>&ourmap, vector<int>&color) {

	queue<int> q;
	color[start] = 1;
	q.push(start);
	while (q.size() != 0) {

		int front = q.front();
		debug(front);
		q.pop();
		int col = color[front];
		vector<int> temp = ourmap[front];
		for (int i = 0; i < temp.size(); i++) {
			if (color[temp[i]] != -1) {
				if (color[temp[i]] == col) {
					return false;
				}
			}
			else {
				color[temp[i]] = 1 - col;
				q.push(temp[i]);
			}
		}
	}
	return true;

}
