//
// Created by 王阳 on 2018/7/29.
//

#include "header.h"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    virtual ~Iterator();

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int i = 0;
    int n;
    vector<int> v;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        this->n = int(nums.size());
        this->v = nums;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        int MaxValue = INT_MAX;
        for (int j = 0; j < this->n; ++j) {
            if (this->v[i] > MaxValue) {
                MaxValue = this->v[i];
            }
        }
        return MaxValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int res = this->v[i];
        i++;
        return res;
    }

    bool hasNext() const {
        return i < this->n;
    }
};

int main() {
    return 0;
}
