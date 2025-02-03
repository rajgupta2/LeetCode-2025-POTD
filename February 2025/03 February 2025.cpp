/*
Longest Strictly Increasing or Strictly Decreasing Subarray
You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n=arr.size();
        int cnt=1;
        if(n==0) return 0;
        if(n==1) return 1;
        int maxi=1;
        int increasing=(arr[0]<arr[1])?1:0;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                if(increasing || cnt==1) cnt++; else cnt=2;
                increasing=1;
            }else if(arr[i-1]>arr[i]){
                if(!increasing || cnt==1) cnt++; else cnt=2;
                increasing=0;
            }else{
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;

    }
};