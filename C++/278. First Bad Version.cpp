//
// Created by 王阳 on 2018/4/24.
//

#include "header.h"
/**
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check.
 * Since each version is developed based on the previous version,
 * all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
 * which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version.
 * You should minimize the number of calls to the API.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    /**
     * 该题主要考察二分查找。可以把1，2，...n一系列版本表示为
     * good，good,......,good，bad, bad，.....，只需通过二分查找算法进行判断，
     * 需要注意的是：如果发现当前版本是好的，则需要将start指向mid的下一个位置。
     */
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int ver = 0;
        while (low < high) {
            ver = low + (high - low) / 2;
            if (isBadVersion(ver)) {
                high = ver;
            } else {
                low = ver + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}