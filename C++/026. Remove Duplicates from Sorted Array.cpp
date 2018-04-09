//
// Created by 王阳 on 2018/4/9.
//

/**
 * Given a sorted array, remove the duplicates in-place such that each element
 * appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 */
#include "header.h"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        auto it = nums.begin();
        for (int i = 0; i < int(nums.size()); i++) {
            int j;
            for (j = 0; true; j++) { // 重复个数。
                if (i + j + 1 >= int(nums.size())) {
                    break;
                } else if (nums[i] == nums[i + 1 + j]) {
//                    printf("重复元素：%d.\n", nums[i + 1 + j]);
                    continue;
                } else {
                    break;
                }
            }

            while (j > 0) {
                nums.erase(it + i + j); // 除去重复。
                printf("索引为：%d.\n", i + j);
                j--;
            }

//            for (int x : nums) {
//                printf("x = %d.\n", x);
//            }
        }
        return int(nums.size());
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(10);
    a.push_back(100);

//    for (int x : a) {
//        printf("x = %d\n", x);
//    }

    printf("size = %d\n", int(a.size()));
    printf("answer = %d\n", solution->removeDuplicates(a));
    printf("---\n");
    printf("size = %d\n", int(a.size()));
//    for (int x : a) {
//        printf("x = %d\n", x);
//    }
    return 0;
}