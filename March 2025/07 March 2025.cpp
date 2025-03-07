/*
Closest Prime Numbers in Range
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
*/
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int upperLimit = right;
            // Step 1: Get all prime numbers up to 'right' using sieve
            vector<int> sieveArray = sieve(upperLimit);

            vector<int>
                primeNumbers;  // Store all primes in the range [left, right]
            for (int num = left; num <= right; num++) {
                // If number is prime add to the primeNumbers list
                if (sieveArray[num] == 1) {
                    primeNumbers.push_back(num);
                }
            }

            // Step 2: Find the closest prime pair
            if (primeNumbers.size() < 2)
                return vector<int>{-1, -1};  // Less than two primes available

            int minDifference = INT_MAX;
            vector<int> closestPair(2, -1);  // setting initial values

            for (int index = 1; index < primeNumbers.size(); index++) {
                int difference = primeNumbers[index] - primeNumbers[index - 1];
                if (difference < minDifference) {
                    minDifference = difference;
                    closestPair[0] = primeNumbers[index - 1];
                    closestPair[1] = primeNumbers[index];
                }
            }

            return closestPair;
        }

    private:
        vector<int> sieve(int upperLimit) {
            // Initiate an int array to mark prime numbers
            vector<int> sieve(upperLimit + 1,
                              1);  // Assuming all numbers as prime initially

            // 0 and 1 are not prime
            sieve[0] = 0;
            sieve[1] = 0;

            for (int number = 2; number * number <= upperLimit; number++) {
                if (sieve[number] == 1) {
                    // Mark all multiples of 'number' as non-prime
                    for (int multiple = number * number; multiple <= upperLimit;
                         multiple += number) {
                        sieve[multiple] = 0;
                    }
                }
            }
            return sieve;
        }
    };