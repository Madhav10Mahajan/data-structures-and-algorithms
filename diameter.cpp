void helper(int start, unordered_map<int, vector<int>>&ourmap, unordered_map<int, bool>&visited, long long &count, long long &maxi, long long &node) {

	visited[start] = true;
	vector<int> temp = ourmap[start];
	if (count > maxi) {
		maxi = count;
		node = start;
	}
	for (int i = 0; i < temp.size(); i++) {
		if (visited[temp[i]] != true) {
			count++;
			helper(temp[i], ourmap, visited, count, maxi, node);
		}
	}
	count--;
}
void solve() {

	long long n;
	cin >> n;
	unordered_map<int, vector<int>> ourmap;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		ourmap[a].push_back(b);
		ourmap[b].push_back(a);
	}
	unordered_map<int, bool> visited(false);
	long long count = 0;
	long long maxi = -1e9;
	long long node1 = -1;
	helper(1, ourmap, visited, count, maxi, node1);
	visited.clear();
	count = 0;
	maxi = -1e9;
	long long node2 = -1;
	helper(node1, ourmap, visited, count, maxi, node2);
	cout << maxi << endl;
}
