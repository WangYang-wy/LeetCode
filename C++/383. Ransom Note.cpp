//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        int n_r = int(ransomNote.length());
        int n_m = int(magazine.length());
        for (int i = 0; i < n_m; ++i) {
            a[magazine[i] - 'a'] += 1;
        }
        for (int i = 0; i < n_r; ++i) {
            if (0 == a[ransomNote[i] - 'a']) {
                return false;
            }
            a[ransomNote[i] - 'a']--;
        }
        return true;
    }
};

int main() {
    return 0;
}
