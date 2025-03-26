/*
Minimum Operations to Make a Uni-Value Grid
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
*/
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> numsArray;
            int result = 0;

            // Flatten the grid into numsArray
            for (int row = 0; row < grid.size(); row++) {
                for (int col = 0; col < grid[0].size(); col++) {
                    numsArray.push_back(grid[row][col]);
                }
            }

            int length = numsArray.size();

            // Partially sorts the array so that the median element is placed at the
            // middle index
            nth_element(numsArray.begin(), numsArray.begin() + length / 2,
                        numsArray.end());

            // Store the median element as the final common value to make all
            // elements equal to
            int finalCommonNumber = numsArray[length / 2];

            for (int number : numsArray) {
                // If the remainder when divided by x is different for any number,
                // return -1
                if (number % x != finalCommonNumber % x) return -1;
                // Add the number of operations required to make the current number
                // equal to finalCommonNumber
                result += abs(finalCommonNumber - number) / x;
            }

            return result;
        }
    };