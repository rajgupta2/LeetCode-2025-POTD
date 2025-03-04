/*
Check if Number is a Sum of Powers of Three
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
An integer y is a power of three if there exists an integer x such that y == 3x.
*/
class Solution {
    public:
        bool checkPowersOfThree(int n) {
             while (n > 0) {
                // Check if this power should be used twice
                if (n % 3 == 2) return false;

                // Divide n by 3 to move to the next greater power
                n /= 3;
            }

            // The ternary representation of n consists only of 0s and 1s
            return true;
        }
    };