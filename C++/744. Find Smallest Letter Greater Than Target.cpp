//
// Created by 王阳 on 2018/5/12.
//

#include "header.h"

/**
 * Given a list of sorted characters letters containing only lowercase letters,
 * and given a target letter target, find the smallest element in the list that
 * is larger than the given target.
 * Letters also wrap around. For example, if the target is target = 'z' and
 * letters = ['a', 'b'], the answer is 'a'.
 */

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int n = int(letters.size());
        int lower = 0;
        int high = n - 1;
        while (lower <= high) {
            int mid = lower + (high - lower) / 2;
            if (target >= letters[mid]) {
                lower = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return lower < n ? letters[lower] : letters[0];
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}