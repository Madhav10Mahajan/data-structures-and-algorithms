class maxheap {
public:
	vector<int> arr;
	void insert(int element) {

		arr.push_back(element);
		int childindex = arr.size() - 1;
		int parentindex = (childindex - 1) / 2;
		while (parentindex >= 0 && arr[childindex] > arr[parentindex]) {
			swap(arr[childindex], arr[parentindex]);
			childindex = parentindex;
			parentindex = (childindex - 1) / 2;
		}
	}
	int deleteelement() {

		if (arr.size() == 0) {
			return -1;
		}
		int data = arr[0];
		arr[0] = arr[arr.size() - 1];
		arr.pop_back();
		int parentindex = 0;
		int leftchildindex = 2 * parentindex + 1;
		int rightchildindex = 2 * parentindex + 2;
		int maxindex = parentindex;
		while (leftchildindex <= arr.size() - 1 && rightchildindex <= arr.size() - 1) {
			if (arr[leftchildindex] > arr[maxindex]) {
				maxindex = leftchildindex;
			}
			if (arr[rightchildindex] > arr[maxindex]) {
				maxindex = rightchildindex;
			}
			if (maxindex == parentindex) {
				break;
			}
			swap(arr[maxindex], arr[parentindex]);
			parentindex = maxindex;
			leftchildindex = 2 * parentindex + 1;
			rightchildindex = 2 * parentindex + 2;
			maxindex = parentindex;
		}
		return data;
	}
	int getmax() {

		if (arr.size() == 0) {
			return -1;
		}
		return arr[0];
	}
	int size() {
		return arr.size();
	}
};
void solve() {

	maxheap m;
	m.insert(1);
	m.insert(2);
	m.insert(3);
	m.insert(4);
	m.insert(5);
	cout << m.getmax() << endl;
	m.deleteelement();
	cout << m.getmax() << endl
}
