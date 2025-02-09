/*
Count Number of Bad Pairs
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
Return the total number of bad pairs in nums.
*/
class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long cnt = 0;
        unordered_map<int, int> diffCount;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int diff = i - nums[i];
            int goodPairs = diffCount[diff];
            cnt += i - goodPairs;
            diffCount[diff]++;
        }
        return cnt;
    }
};