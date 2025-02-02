/*
Check if Array Is Sorted and Rotated
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/
class Solution {
public:
    bool check(vector<int>& arr) {
        int n=arr.size();
        int rotated=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1] && rotated!=-1) return false;
            if(arr[i]>arr[i+1]){
                rotated=i;
            }
        }
        for(int i=rotated+1;i<n-1;i++){
            if(arr[i]>arr[i+1]) return false;
        }
        if(rotated!=-1) return (arr[0]>=arr[n-1]);
        return true;
    }
};