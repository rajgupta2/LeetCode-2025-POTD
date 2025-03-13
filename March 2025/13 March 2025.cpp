/*
Zero Array Transformation II
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].
Each queries[i] represents the following action on nums:
Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.
Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.
*/

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size(), sum = 0, k = 0;
            vector<int> differenceArray(n + 1);

            // Iterate through nums
            for (int index = 0; index < n; index++) {
                // Iterate through queries while current index of nums cannot equal
                // zero
                while (sum + differenceArray[index] < nums[index]) {
                    k++;

                    // Zero array isn't formed after all queries are processed
                    if (k > queries.size()) {
                        return -1;
                    }
                    int left = queries[k - 1][0], right = queries[k - 1][1],
                        val = queries[k - 1][2];

                    // Process start and end of range
                    if (right >= index) {
                        differenceArray[max(left, index)] += val;
                        differenceArray[right + 1] -= val;
                    }
                }
                // Update prefix sum at current index
                sum += differenceArray[index];
            }
            return k;
        }
    };