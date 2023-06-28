void solve() {

	long long n, m, q;
	cin >> n >> m >> q;
	vector <vector<long long >> distance(n + 1, vector<long long>(n + 1, 1LL * n * 1e9 + 1LL));
	for (int i = 0; i < m; i++) {
		long long a, b, w;
		cin >> a >> b >> w;
		distance[a][b] = w;
		distance[b][a] = w;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) {
				distance[i][j] = 0;
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (distance[a][b] >= 1LL * n * 1e9 + 1LL) {
			cout << -1 << endl;
		}
		else {
			cout << distance[a][b] << endl;
		}
	}
}
