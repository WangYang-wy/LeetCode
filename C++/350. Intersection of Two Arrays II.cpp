//
// Created by 王阳 on 2018/4/17.
//

#include "header.h"

/**
 * Given two arrays, write a function to compute their intersection.
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that
 * you cannot load all elements into the memory at once?
 */

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        int n_1 = int(nums1.size());
        int n_2 = int(nums2.size());

        vector<bool> flag_1;

        for (int i = 0; i < n_1; i++) {
            flag_1.push_back(false);
        }

        vector<bool> flag_2;

        for (int i = 0; i < n_2; i++) {
            flag_2.push_back(false);
        }

        for (int i = 0; i < n_1; i++) {
            for (int j = 0; j < n_2; j++) {
                if (nums1[i] == nums2[j] && !flag_2[j] && !flag_1[i]) {
                    res.push_back(nums1[i]);
                    flag_2[j] = true;
                    flag_1[i] = true;
                }
            }
        }
        return res;
    }

    /**
     * 比较高效的算法，先排序，然后每个数组都有哨兵。多思考一下，将无序的东西变成有序的东西，
     * 这样的做法对效率是否有提高？
     */
    vector<int> intersect_high_performance(vector<int> &nums1, vector<int> &nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        vector<int> x;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                x.push_back(nums2[j]);
                i++;
                j++;
            } else {
                if (nums1[i] < nums2[j]) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return x;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}