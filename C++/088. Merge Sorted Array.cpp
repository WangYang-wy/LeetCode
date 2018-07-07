//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 * to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include "header.h"

class Solution {
public:
    // 不知道为什么在本地运行正确，但是提交之后总是TIME ERROR。
    void merge_TE(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (0 == n) {
            return;
        }
        auto it = nums1.begin();
        for (int i = 0, j = 0; j < n && i < m; j++) {
            if (nums2[j] <= nums1[i]) {
                nums1.insert(it + i, nums2[j]);
                printf("i = %d\n", i);
                printf("j = %d\n", j);
                printf("nums2[j] = %d\n", nums2[j]);
            } else {
                i++;
                j--; // j不移位。
            }
        }
//        for (int i = 0; i < m + n; i++) {
//            std::cout << i << ":" << nums1[i] << std::endl;
//        }
        while (nums1.size() > n + m) {
            nums1.pop_back();
        }
        printf("length = %d\n", int(nums1.size()));
        for (int i = 0; i < m + n; i++) {
            std::cout << i << ":" << nums1[i] << std::endl;
        }
    }

    // 创建一个新的数组，来保存融合后的结果。
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> nums;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    nums.push_back(nums1[i]);
                    i++;
                } else {
                    nums.push_back(nums2[j]);
                    j++;
                }
            } else if (i < m) {
                nums.push_back(nums1[i]);
                i++;
            } else if (j < n) {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = nums;
        for (int i = 0; i < m + n; i++) {
            std::cout << i << ":" << nums1[i] << std::endl;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> s1;
    s1.push_back(4);
    s1.push_back(5);
    s1.push_back(6);
    s1.push_back(0);
    s1.push_back(0);
    s1.push_back(0);
//    printf("s1 length = %d\n", s1.size());

    vector<int> s2;
    s2.push_back(1);
    s2.push_back(2);
    s2.push_back(3);
//    printf("s2 length = %d\n", s2.size());
    solution->merge(s1, 3, s2, 3);
    return 0;
}