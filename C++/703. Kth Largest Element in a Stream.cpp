//
// Created by 王阳 on 2018/8/20.
//

#include "header.h"

class KthLargest {
private:
    vector<int> heap;
    int size;
    int has = 0;

    void initHeap(int k) {
        this->heap.clear();
        this->size = k;
        for (int i = 0; i < k; ++i) {
            this->heap.push_back(INT_MAX);
        }
    }

    void insert(int val) {
        if (this->has < this->size) {
            this->heap[this->has++] = val;
            this->heapsort();
        } else if (val <= this->getKthLargest()) { // 不需要更新。
            ;
        } else { // 超出范围，而且需要更新。
            this->swap(0, this->size - 1);
            this->heap[this->size - 1] = val;
            this->heapsort();
        }
        // std::cout << this->heap[0] << std::endl;
    }

    void heapsort() {
        int index = this->has / 2 - 1; // 第一个非叶子节点。
        for (int i = index; i >= 0; --i) {
            this->adjust(i); // 将该位置的数字放到该放的地方去。
        }
    }

    void adjust(int i) {
        int val = this->heap[i];
        int left = i * 2 + 1;
        int right = left + 1;
        int min_index = left;

        while (left < this->has) {
            // 找出左右子节点的最大值。
            if (right < this->has && this->heap[right] < this->heap[left]) {
                min_index = right;
            }
            if (val <= this->heap[min_index]) { // 已经是小顶堆。
                break;
            }
            val = this->heap[min_index];
            this->swap(i, min_index);
            left = 2 * min_index + 1;
        }
    }

    void swap(int a, int b) {
        int tmp = this->heap[a];
        this->heap[a] = this->heap[b];
        this->heap[b] = tmp;
    }

    int getKthLargest() {
        return this->heap[0];
    }

public:
    KthLargest(int k, vector<int> nums) {
        int n = int(nums.size());
        this->initHeap(k);
        for (auto x:nums) {
            this->insert(x);
        }
    }

    int add(int val) {
        this->insert(val);
        return this->getKthLargest();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */

int main() {
    return 0;
}