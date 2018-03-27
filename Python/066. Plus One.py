"""
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
"""


class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        length = len(digits)
        flag = 0
        digits[-1] = digits[-1] + 1
        # print(digits)
        if (digits[-1] > 9):
            digits[-1] = digits[-1] - 10
            flag = 1

        for i in range(1, length):
            index = length - 1 - i
            res = digits[index]
            if (flag):
                res = res + 1
                flag = 0 # 使用了进位。

            if (res > 9):
                res = res - 10
                flag = 1 # 产生了进位。

            digits[index] = res

        if (flag):
            digits.insert(0, 1)

        return digits


if __name__ == '__main__':
    solution = Solution()
    print(solution.plusOne([1, 9]))
