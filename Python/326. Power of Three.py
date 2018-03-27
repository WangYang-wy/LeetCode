"""
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
"""
import math

class Solution:
    def isPowerOfThree_loop(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while (n % 3 == 0):
            n = n / 3

        if (1 == n):
            return True
        else:
            return False

    def isPowerOfThree_int(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and 3 ** 19 % n == 0

    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and int (math.log10(n) / math.log10(3)) - math.log10(n) / math.log10(3) == 0