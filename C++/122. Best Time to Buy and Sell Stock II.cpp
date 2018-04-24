//
// Created by 王阳 on 2018/4/24.
//
/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like
 * (i.e., buy one and sell one share of the stock multiple times).
 */

#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/pistolove/article/details/43155725
 * 只不过该题考查数组中所有相邻且递增元素的数值之差的总和。
 * 只要第i+1天的值大于第i天的值，则可买入，求得利润（差值），遍历整个数组，得到所用差值之和即为总的利润。
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = int(prices.size());
        if (n <= 1)
            return 0;

        int min = prices[0];
        int profit = 0;

        // 线性时间，假设当前的价格最小。
        for (int i = 0; i < n; i++) {
            if (min > prices[i]) {
                min = prices[i];
            } else {
                profit += prices[i] - min; // 同一天卖了又买，相当于没有卖。
                min = prices[i];
            }
        }
        return profit;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}