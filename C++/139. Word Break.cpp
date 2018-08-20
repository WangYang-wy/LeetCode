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
    Trie() {
        head = new TrieNode();
    }

    void insert(string word) {
        TrieNode *root = this->head;
        int n = int(word.length());
        for (int i = 0; i < n; ++i) {
            if (nullptr == root->childs[word[i] - 'a']) {
                root->childs[word[i] - 'a'] = new TrieNode();
            }
            root = root->childs[word[i] - 'a'];
        }
        root->isWord = true;
    }

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
};

class Solution {
private:
    Trie *myWordDict = new Trie();
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        long m = s.length();
        vector<bool> f;
        for (int i = 0; i < m + 1; ++i) {
            f.push_back(false);
        }
        f[0] = true;
        for (auto x:wordDict) {
            myWordDict->insert(x); // 插入字典。
        }

        for (int i = 0; i < m + 1; ++i) {
            if (f[i]) {
                for (int j = i; j < m + 1; ++j) {
                    if (myWordDict->search(s.substr(i, j - i))) {
                        f[j] = true;
                    }
                }
            }
        }
        return f[m];
    }
};

int main() {
    return 0;
}