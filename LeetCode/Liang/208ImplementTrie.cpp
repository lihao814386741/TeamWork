class TrieNode {
public:
    // Initialize your data structure here.
    bool isWord;
    unordered_map<char, TrieNode*> hash;
    TrieNode() {
        isWord = false;
    }
    ~TrieNode() {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); ++i) {
            if (itr->hash.find(word[i]) == itr->hash.end()) {
                itr->hash[word[i]] = new TrieNode();    
            }
            itr = itr->hash[word[i]];
        }
        itr->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); ++i) {
            if (itr->hash.find(word[i]) == itr->hash.end()) {
                return false;
            } else {
                itr = itr->hash[word[i]];
            }
        }
        return itr->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *itr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (itr->hash.find(prefix[i]) == itr->hash.end()) { // Forget the itr->hash.end();
                return false;
            } else {
                itr = itr->hash[prefix[i]];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
