/*
Divide Array Into Equal Pairs
You are given an integer array nums consisting of 2 * n integers.
You need to divide nums into n pairs such that:
Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.
*/
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
         int n=nums.size();
         if(n%2!=0) return false;
         vector<int> fre(501,0);
         for(auto e:nums)
         fre[e]++;
         for(auto f:fre){
            if(f%2!=0) return false;
         }
         return true;
        }
    };