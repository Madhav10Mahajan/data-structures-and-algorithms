void helper(int n, vector<int>&arr, int parentindex) {

	int leftchildindex = 2 * parentindex + 1;
	int rightchildindex = 2 * parentindex + 2;
	int maxindex = parentindex;
	if (leftchildindex <= n - 1 && arr[leftchildindex] > arr[maxindex]) {
		maxindex = leftchildindex;
	}
	if (rightchildindex <= n - 1 && arr[rightchildindex] > arr[maxindex]) {
		maxindex = rightchildindex;
	}
	if (maxindex != parentindex) {
		swap(arr[maxindex], arr[parentindex]);
		parentindex = maxindex;
		helper(n, arr, parentindex);
	}

}
void heapify(vector<int>&arr, int n) {

	for (int i = n / 2; i >= 0; i--) {
		helper(n, arr, i);
	}
}
void heapsort(vector<int>&arr) {

	int n = arr.size();
	heapify(arr, n);
	int size = n;
	while (size > 0) {

		swap(arr[0], arr[size - 1]);
		size--;
		heapify(arr, size);
	}

}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	heapsort(arr);
	debug(arr);
}
