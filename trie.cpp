template <typename T>
class trienode {
public:
	char data;
	trienode<char>* children[26];
	bool isterminal;
	trienode(char data) {
		this->data = data;
		this->isterminal = false;
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}
};
class trie {
public:
	trienode<char>* root;
	trie() {
		root = new trienode<char>('\0');
	}
	void insertwordhelper(int i, trienode<char>*root, string word) {

		if (i >= word.size()) {
			root->isterminal = true;
			return;
		}
		int index = word[i] - 'a';
		trienode<char>* child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new trienode<char>(word[i]);
			root->children[index] = child;
		}
		insertwordhelper(i + 1, child, word);
	}
	void insertword(string word) {
		insertwordhelper(0, root, word);
	}
	bool searchwordhelper(int i, trienode<char>* root, string word) {

		if (i >= word.size()) {
			if (root->isterminal == true) {
				return true;
			}
			return false;
		}
		int index = word[i] - 'a';
		trienode<char>* child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return false;
		}
		return searchwordhelper(i + 1, child, word);
	}
	bool searchword(string word) {
		return searchwordhelper(0, root, word);
	}
	void deletewordhelper(int i, trienode<char>*root, string word) {

		if (i >= word.size()) {
			root->isterminal = false;
			return;
		}
		int index = word[i] - 'a';
		trienode<char>* child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return;
		}
		return deletewordhelper(i + 1, child, word);
	}
	void deleteword(string word) {
		deletewordhelper(0, root, word);
	}

};

