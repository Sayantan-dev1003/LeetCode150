class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfsSearch(const string& word, int index, TrieNode* node) {
        if (!node)
            return false;
        if (index == word.size())
            return node->isEnd;

        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfsSearch(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        } else {
            return dfsSearch(word, index + 1, node->children[c - 'a']);
        }
    }

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) { return dfsSearch(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
