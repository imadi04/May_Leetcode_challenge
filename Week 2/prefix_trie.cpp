class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
    TrieNode *root;

	public :
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    void insert(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		insert(child, word.substr(1));
	}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(root, word);
    }
    bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return search(child, word.substr(1));
	}

    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(root, word);
    }
    bool startsWith(TrieNode *root, string word) {
		if(word.size() == 0) {
			return true;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return startsWith(child, word.substr(1));
	}

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */