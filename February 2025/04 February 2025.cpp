/*
Maximum Ascending Subarray Sum
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
*/
class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1])
            {
                sum+=arr[i];
                maxi=max(maxi,sum+arr[i+1]);
            }else{
                sum=0;
                maxi=max(maxi,max(arr[i],arr[i+1]));
            }
        }
        return maxi;
    }
};