/*
Minimum Operations to Make Binary Array Elements Equal to One I
You are given a binary array nums.
You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.
Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
*/
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int count = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            // only looking forward to the last element
            if (nums[i - 2] == 0)
            {
                count++;
                // flip i-2 and i-1 and i
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size())
            return count;
        return -1;
    }
};