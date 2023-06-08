void dijkstra(int start, unordered_map<int, vector<pair<int, int>>>&ourmap, vector<int>&distance) {

	distance[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
	minheap.push({0, start});
	while (minheap.size() != 0) {

		pair<int, int> front = minheap.top();
		minheap.pop();
		int d = front.first;
		int node = front.second;
		vector<pair<int, int>> temp = ourmap[node];
		for (int i = 0; i < temp.size(); i++) {
			int childnode = temp[i].first;
			int weight = temp[i].second;
			if (d + weight < distance[childnode]) {
				distance[childnode] = d + weight;
				minheap.push({distance[childnode], childnode});
			}
		}
	}
}
