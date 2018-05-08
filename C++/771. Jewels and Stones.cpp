//
// Created by 王阳 on 2018/5/8.
//

#include "header.h"

/**
 * You're given strings J representing the types of stones that are jewels,
 * and S representing the stones you have.  Each character in S is a type of stone you have.
 * You want to know how many of the stones you have are also jewels.
 * The letters in J are guaranteed distinct, and all characters in J and S are letters.
 * Letters are case sensitive, so "a" is considered a different type of stone from "A".
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n_j = int(J.size());
        int n_s = int(S.size());
        int count = 0;
        for (int i = 0; i < n_j; i++) {
            for (int j = 0; j < n_s; j++) {
                if (J[i] == S[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}