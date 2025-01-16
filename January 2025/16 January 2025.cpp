/*
Bitwise XOR of All Pairings
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).
Return the bitwise XOR of all integers in nums3.
*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int numxr=0;

        if(n%2==0 && m%2==0) return 0;
        if(n%2!=0 && m%2!=0){
            for(int i=0;i<n;i++) numxr^=nums1[i];
            for(int i=0;i<m;i++) numxr^=nums2[i];
            return numxr;
        }
        if(n%2==0){
            for(int i=0;i<n;i++) numxr^=nums1[i];
            return numxr;
        }
        for(int i=0;i<m;i++) numxr^=nums2[i];
        return numxr;
    }
};