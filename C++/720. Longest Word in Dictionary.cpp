//
// Created by 王阳 on 2018/5/8.
//

#include "header.h"

/**
 * Given a list of strings words representing an English Dictionary,
 * find the longest word in words that can be built one character at a
 * time by other words in words. If there is more than one possible answer,
 * return the longest word with the smallest lexicographical order.
 */

class Solution {
public:
    // 参考博客：https://www.cnblogs.com/grandyang/p/7817011.html

    /**
     * 首先建立一个空的哈希set，然后我们直接遍历排序后的字典，对于当前的单词，如果当前单词长度为1，
     * 或者该单词去掉最后一个字母后在集合中存在，这也不难理解，长度为1，说明是起始单词，不需要的多余的判断，
     * 否则的话就要判断其去掉最后一个字母后的单词是否在集合中存在，存在的话，才说明其中间单词都存在，
     * 因为此时是从短单词向长单词遍历，只要符合要求的才会加入集合，所以一旦其去掉尾字母的单词存在的话，
     * 那么其之前所有的中间情况都会在集合中存在。我们更新结果res时，要判断当前单词长度是否大于结果res的长度，
     * 因为排序过后，默认先更新的字母顺序小的单词，所有只有当当前单词长度大，才更新结果res，
     * 之后别忘了把当前单词加入集合中，
     */
    string longestWord(vector<string> &words) {
        // 先进行字典排序。
        string res = "";
        unordered_set <string> s; // 无序的集合。
        sort(words.begin(), words.end()); // 排序。
        for (string word : words) { // 遍历。
            // 长度为1，或者，
            if (1 == word.size() || s.count(word.substr(0, word.size() - 1))) {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};


int main() {
    Solution *solution = new Solution();
    return 0;
}