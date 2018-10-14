//
// Created by 王阳 on 2018/10/13.
//

#include "header.h"

class Solution {
private:
    int length = 0;
    int max_profit = 0;
    int is_buy = false;

    int max(int a, int b) {
        return a > b ? a : b;
    }

    // status 表示上一步的状态。
    void search(int idx, vector<int> &prices, int status, int profit) {
        if (idx == this->length) {
            if (!this->is_buy) {
                this->max_profit = this->max(this->max_profit, profit);
            }
            return;
        }

        if (0 == idx) {
            // 购买。
            this->is_buy = true;
            this->search(idx + 1, prices, -1, profit - prices[idx]);
            this->is_buy = false;
            // 不操作。
            this->search(idx + 1, prices, 0, profit);
        } else {
            if (this->is_buy) { // 买入状态。
                if (profit + prices[idx] > 0) {
                    // 卖出。
                    this->is_buy = false;
                    this->search(idx + 1, prices, 1, profit + prices[idx]);
                    this->is_buy = true;
                }
                // 不操作。
                this->search(idx + 1, prices, 0, profit);
            } else { // 手上没有股票。
                // 购买的上一步必须是不操作。
                if (0 == status) {
                    this->is_buy = true;
                    this->search(idx + 1, prices, -1, profit - prices[idx]);
                    this->is_buy = false;
                }
                // 不操作。
                this->search(idx + 1, prices, 0, profit);
            }
        }
    }

public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int len = int(prices.size());
        vector<int> buy(len + 1, 0), sell(len + 1, 0);
        buy[1] = -prices[0];
        for (int i = 2; i <= len; i++) {
            buy[i] = max(sell[i - 2] - prices[i - 1], buy[i - 1]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i - 1]);
        }
        return sell[len];
    }

    int maxProfit_TLE(vector<int> &prices) {
        this->length = int(prices.size());
        this->search(0, prices, 0, 0);
        return this->max_profit;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> prices = {48, 12, 60, 93, 97};
    solution->maxProfit(prices);
    delete solution;
    return 0;
}