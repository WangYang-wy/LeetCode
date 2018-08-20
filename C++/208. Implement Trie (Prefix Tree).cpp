//
// Created by 王阳 on 2018/8/20.
//

#include "header.h"

class TrieNode {
public:
    bool isWord;
    TrieNode *childs[26] = {0};

    TrieNode() {
        this->isWord = false;
    }
};

class Trie {
private:
    TrieNode *head;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *root = this->head;
        int n = int(word.length());
        for (int i = 0; i < n; ++i) {
            if (nullptr == root->childs[word[i] - 'a']) {
                root->childs[word[i] - 'a'] = new TrieNode();
            }
            root = root->childs[word[i] - 'a'];
        }
//        root->childs[word[n - 1] - 'a'] = new TrieNode();
        root->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *root = this->head;
        int n = int(word.length());
        for (int i = 0; i < n; ++i) {
            if (nullptr == root->childs[word[i] - 'a']) {
                return false;
            }
            root = root->childs[word[i] - 'a'];
        }
        return root->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *root = this->head;
        int n = int(prefix.length());
        for (int i = 0; i < n; ++i) {
            if (nullptr == root->childs[prefix[i] - 'a']) {
                return false;
            }
            root = root->childs[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    return 0;
}