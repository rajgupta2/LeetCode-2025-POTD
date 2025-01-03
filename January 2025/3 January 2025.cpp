/*
You are given a 0-indexed integer array nums of length n.
nums contains a valid split at index i if the following are true:
The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n=nums.size();
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long int currSum=0;
        int res=0;
        for(int i=0;i<=n-2;i++){
          currSum+=(long long int)nums[i];
          if(currSum>=sum-currSum)
          res++;
        }
        return res;

    }
};