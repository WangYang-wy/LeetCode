//
// Created by 王阳 on 2018/8/20.
//

#include "header.h"

class Solution {
private:
    vector<vector<string>> mem;
    vector<int> visit;

    void DFS(string &s, unordered_set <string> &wordDict, int pos) {
        visit[pos] = 1;
        for (int i = pos + 1; i <= s.size(); ++i) {
            if (wordDict.find(s.substr(pos, i - pos)) != wordDict.end()) {
                if (i == s.size()) {
                    mem[pos].push_back(s.substr(pos, i - pos));
                    continue;
                }
                if (!visit[i])
                    DFS(s, wordDict, i);
                for (auto &str : mem[i])
                    mem[pos].push_back(s.substr(pos, i - pos) + " " + str);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        visit.resize(s.size());
        unordered_set <string> map(wordDict.begin(), wordDict.end());
        mem.resize(s.size());
        DFS(s, map, 0);
        vector<string> answ = mem[0];
        mem.clear();
        visit.clear();
        return answ;
    }
};

/*
 * 自己写的超时/内存错误代码。
 *
 * 用例为：
 * "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
 * ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
 * 每次判断 startWith()，都会返回 true，就比较难优化这种 case。
 *
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

    bool startWith(string word) {
        TrieNode *root = this->head;
        int n = int(word.length());
        for (int i = 0; i < n; ++i) {
            if (nullptr == root->childs[word[i] - 'a']) {
                return false;
            }
            root = root->childs[word[i] - 'a'];
        }
        return true;
    }
};

class Solution {
private:
    Trie *myWordDict = new Trie();
    vector<string> res;
    vector<string> path;
    vector<bool> f;
    int index = 0;
public:
    void search(int idx, string &s) {
        long m = s.length();
        if (idx == m) {
            string tmp = "";
            for (int i = 0; i < this->index; ++i) {
                tmp += this->path[this->index] + " ";
            }
            this->res.push_back(tmp.substr(0, tmp.length() - 1));
        }

        for (int i = idx; i < m + 1; ++i) {
            if (f[i]) {
                for (int j = i + 1; j < m + 1; ++j) {
                    string sub_str = s.substr(i, j - i);

                    if (!myWordDict->startWith(sub_str)) {
                        break;
                    }

                    if (myWordDict->search(sub_str)) {
                        this->path[this->index] = sub_str;
                        this->index++;
                        f[j] = true;
                        this->search(j, s);
                        this->index--;
                        f[j] = false;
                    }
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        this->path.clear();
        this->res.clear();
        long m = s.length();
        for (int i = 0; i < m + 1; ++i) {
            f.push_back(false);
            this->path.push_back(" ");
        }
        f[0] = true;
        for (auto x:wordDict) {
            myWordDict->insert(x); // 插入字典。
        }
        this->search(0, s);
        return this->res;
    }
};
*/

int main() {
    Solution *solution = new Solution();

    return 0;
}