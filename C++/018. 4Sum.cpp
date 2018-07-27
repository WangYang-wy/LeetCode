//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
private:
    vector<vector<int>> res;
//    vector<int> path;
    vector<bool> visited;
    int last_index;

    /**
     * 递归函数。
     * @param idx 搜索索引。
     * @param nums 数组。
     * @param target 目标值。
     * @param count 使用计数。
     */
    void fun(int idx, vector<int> &nums, int target, int count) {
        if (count > 4) { // 次数多了。
            return;
        }

        int n = int(nums.size());

        // 已经选择，和还能选择的个数不够 4 个。
        if (n - idx < 4 - count) {
            return;
        }

        if (4 == count && 0 == target) { // 选购四个，就可以判断。
            vector<int> path;
            path.clear();
            for (int i = 0; i < this->last_index; ++i) {
                if (this->visited[i] && count > 0) {
                    count--;
                    path.push_back(nums[i]);
                }
            }
            this->res.push_back(path);
            return;
        }

        // 根据排序，如果相同，前面一个不选，当前也不选。
        if (idx > 0 && nums[idx] == nums[idx - 1] && !this->visited[idx - 1]) { // 不选择。
            this->visited[idx] = false;
            this->fun(idx + 1, nums, target, count);
        } else { // 既可以选，也可以不选。
            this->visited[idx] = true;
            if (count == 3) {
                this->last_index = idx;
            }
            this->fun(idx + 1, nums, target - nums[idx], count + 1);

            this->visited[idx] = false;
            this->fun(idx + 1, nums, target, count);
        }
    }

public:
    vector<vector<int>> fourSum_search(vector<int> &nums, int target) {
        res.clear();
        int n = int(nums.size());
        if (n < 4) {
            return this->res;
        }
        sort(nums.begin(), nums.end());
        // 如果最大的四个数都小于目标值，那么不存在。
        if (nums[n - 1] + nums[n - 2] + nums[n - 3] + nums[n - 4] < target) {
            return this->res;
        }

        // 如果最大的四个数都大于目标值，那么不存在。
        if (nums[0] + nums[1] + nums[2] + nums[3] > target) {
            return this->res;
        }

        for (int i = 0; i < n; ++i) {
            this->visited.push_back(false);
        }
        this->fun(0, nums, target, 0);
        return this->res;
    }

    // 三重循环 + 二分查找 + 去重。
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int> > ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int l = j + 1;
                int r = int(nums.size()) - 1;
                while (l < r) {
                    int tmp = nums[i] + nums[j] + nums[l] + nums[r];
                    if (tmp < target)
                        l++;
                    else if (tmp > target)
                        r--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        //erase 函数删除两迭代器之间的元素，unique 返回的是重排后第一个多余元素的位置。
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a = {91277418, 66271374, 38763793, 4092006, 11415077, 60468277, 1122637, 72398035, -62267800, 22082642, 60359529,
         -16540633, 92671879, -64462734, -55855043, -40899846, 88007957, -57387813, -49552230, -96789394, 18318594,
         -3246760, -44346548, -21370279, 42493875, 25185969, 83216261, -70078020, -53687927, -76072023, -65863359,
         -61708176, -29175835, 85675811, -80575807, -92211746, 44755622, -23368379, 23619674, -749263, -40707953,
         -68966953, 72694581, -52328726, -78618474, 40958224, -2921736, -55902268, -74278762, 63342010, 29076029,
         58781716, 56045007, -67966567, -79405127, -45778231, -47167435, 1586413, -58822903, -51277270, 87348634,
         -86955956, -47418266, 74884315, -36952674, -29067969, -98812826, -44893101, -22516153, -34522513, 34091871,
         -79583480, 47562301, 6154068, 87601405, -48859327, -2183204, 17736781, 31189878, -23814871, -35880166,
         39204002, 93248899, -42067196, -49473145, -75235452, -61923200, 64824322, -88505198, 20903451, -80926102,
         56089387, -58094433, 37743524, -71480010, -14975982, 19473982, 47085913, -90793462, -33520678, 70775566,
         -76347995, -16091435, 94700640, 17183454, 85735982, 90399615, -86251609, -68167910, -95327478, 90586275,
         -99524469, 16999817, 27815883, -88279865, 53092631, 75125438, 44270568, -23129316, -846252, -59608044,
         90938699, 80923976, 3534451, 6218186, 41256179, -9165388, -11897463, 92423776, -38991231, -6082654, 92275443,
         74040861, 77457712, -80549965, -42515693, 69918944, -95198414, 15677446, -52451179, -50111167, -23732840,
         39520751, -90474508, -27860023, 65164540, 26582346, -20183515, 99018741, -2826130, -28461563, -24759460,
         -83828963, -1739800, 71207113, 26434787, 52931083, -33111208, 38314304, -29429107, -5567826, -5149750, 9582750,
         85289753, 75490866, -93202942, -85974081, 7365682, -42953023, 21825824, 68329208, -87994788, 3460985, 18744871,
         -49724457, -12982362, -47800372, 39958829, -95981751, -71017359, -18397211, 27941418, -34699076, 74174334,
         96928957, 44328607, 49293516, -39034828, 5945763, -47046163, 10986423, 63478877, 30677010, -21202664,
         -86235407, 3164123, 8956697, -9003909, -18929014, -73824245};
//    solution->fourSum_search(a, -236727523); // 运行时间太长。
    solution->fourSum(a, -236727523);
    delete solution;
    return 0;
}
