//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction
 * (i.e., buy one and sell one share of the stock), design
 * an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = int(prices.size());
        int max_count = 0; // 如果小于等于0，那么就不买卖。
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = prices[j] - prices[i];
                if (count > max_count) {
                    max_count = count;
                }
            }
        }
        return max_count;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}