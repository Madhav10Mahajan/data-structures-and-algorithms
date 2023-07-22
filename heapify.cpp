void helper(int data, vector<int>&arr, int parentindex) {

	int n = arr.size();
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
		helper(arr[parentindex], arr, parentindex); 
	}

}
void heapify(vector<int>&arr) {

	int n = arr.size();
	for (int i = n / 2; i >= 0; i--) {
		helper(arr[i], arr, i);
	}
}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

}
