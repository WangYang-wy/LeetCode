"""
Write a function that takes a string as input and returns the string reversed.

Example:Given s = "hello", return "olleh".
"""


class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = str()
        for item in s:
            res = item + res

        return res

if __name__ == '__main__':
    solution = Solution()
    print(solution.reverseString("hello"))
    print(1)
