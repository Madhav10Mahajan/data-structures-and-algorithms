void mergesortedarrays(vector<int>&arr, int start, int mid, int end) {

	int num1 = mid - start + 1;
	int num2 = end - mid;
	int arr1[num1];
	int arr2[num2];
	for (int i = 0; i < num1; i++) {
		arr1[i] = arr[start + i];
	}
	for (int i = 0; i < num2; i++) {
		arr2[i] = arr[mid + i + 1];
	}
	int i = 0;
	int j = 0;
	int k = start;
	while (i < num1 && j < num2) {
		if (arr1[i] < arr2[j]) {
			arr[k] = arr1[i];
			i++;
			k++;
		}
		else {
			arr[k] = arr2[j];
			j++;
			k++;
		}
	}
	while (i < num1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while (j < num2) {
		arr[k] = arr2[j];
		j++;
		k++;
	}
}
void mergesorthelper(int start, int end, vector<int>&arr) {

	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	mergesorthelper(start, mid, arr);
	mergesorthelper(mid + 1, end, arr);
	mergesortedarrays(arr, start, mid, end);
}
void mergesort(vector<int>&arr) {

	int start = 0;
	int end = arr.size() - 1;
	mergesorthelper(start, end, arr);
}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergesort(arr);
	debug(arr);
}
