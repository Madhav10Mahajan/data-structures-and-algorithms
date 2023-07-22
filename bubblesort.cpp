void bubblesort(vector<int>&arr) {

	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubblesort(arr);
	debug(arr);
}
