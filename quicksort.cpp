int partition(vector<int>&arr, int start, int end) {

	int data = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= data) {
			count++;
		}
	}
	int index = start + count;
	swap(arr[start], arr[index]);
	int i = start;
	int j = end;
	while (i < index && j > index) {
		if (arr[i] <= arr[index]) {
			i++;
		}
		else if (arr[j] > arr[index]) {
			j--;
		}
		else {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	return index;
}
void quicksorthelper(int start, int end, vector<int>&arr) {

	if (start >= end) {
		return;
	}
	int c = partition(arr, start, end);
	quicksorthelper(start, c - 1, arr);
	quicksorthelper(c + 1, end, arr);
}
void quicksort(vector<int>&arr) {

	int start = 0;
	int end = arr.size() - 1;
	quicksorthelper(start, end, arr);
}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quicksort(arr);
	debug(arr);
}
