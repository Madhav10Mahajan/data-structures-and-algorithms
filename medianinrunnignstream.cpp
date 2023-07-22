int signum(int a, int b) {

	if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
	return -1;
}
void getmedian(int element, int&median, priority_queue<int>&maxheap, priority_queue<int, vector<int>, greater<int>>&minheap) {

	switch (signum(minheap.size(), maxheap.size())) {
	case 0:
		if (element > median) {
			minheap.push(element);
			median = minheap.top();
		}
		else {
			maxheap.push(element);
			median = maxheap.top();
		}
		break;
	case 1:
		if (element < median) {
			maxheap.push(element);
			median = (minheap.top() + maxheap.top()) / 2;
		}
		else {
			int data = minheap.top();
			minheap.pop();
			maxheap.push(data);
			minheap.push(element);
			median = (minheap.top() + maxheap.top()) / 2;
		}
		break;
	case -1:
		if (element > median) {
			minheap.push(element);
			median = (minheap.top() + maxheap.top()) / 2;
		}
		else {
			int data = maxheap.top();
			maxheap.pop();
			minheap.push(data);
			maxheap.push(element);
			median = (minheap.top() + maxheap.top()) / 2;
		}
		break;
	}
}
void solve() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int median = -1;
	for (int i = 0; i < n; i++) {
		getmedian(arr[i], median, maxheap, minheap);
		cout << median << endl;
	}
}
