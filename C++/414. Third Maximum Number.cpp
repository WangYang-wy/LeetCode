//
// Created by 王阳 on 2018/3/30.
//

#include "header.h"

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int index1 = -1;
        int index2 = -1;
        int index3 = -1;

        int count1 = 0;
        int count2 = 0;

        auto it = nums.begin();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max1 = max(max1, nums[i]);
                index1 = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max1) {
                count1++;
            }
        }

        for (int i = 0; i < count1; i++) {
            auto it = nums.begin();
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == max1) {
                    nums.erase(it + i);
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max2) {
                max2 = max(max2, nums[i]);
                index2 = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max2) {
                count2++;
            }
        }

        for (int i = 0; i < count2; i++) {
            auto it = nums.begin();
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == max2) {
                    nums.erase(it + i);
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= max3) {
                max3 = max(max3, nums[i]);
                index3 = i;
                printf("index3 = %d\n", index3);
            }
        }

        printf("index1 = %d\n", index1);
        printf("index2 = %d\n", index2);
//        printf("index3 = %d\n", index3);

        printf("max1 = %d\n", max1);
        printf("max2 = %d\n", max2);
        printf("max3 = %d\n", max3);

        if (-1 != index3) {
            return max3;
        } else {
            return max1;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    // [1,2,-2147483648]
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
//    s.push_back(3);
//    s.push_back(1);
    s.push_back(-2147483648);
    printf("%d\n", solution->thirdMax(s));
    return 0;
}