/*
Merge Two 2D Arrays by Summing Values
You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.
*/
class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> ans;
            int left1=0,left2=0;

            while(left1<nums1.size() && left2<nums2.size()){
                    if(nums1[left1][0]==nums2[left2][0]){
                        int val=nums1[left1][1]+nums2[left2][1];
                        ans.push_back({nums1[left1][0],val});
                        left1++;
                        left2++;
                    }else if(nums1[left1][0]<nums2[left2][0]){
                        ans.push_back(nums1[left1]); left1++;

                    }else{
                        ans.push_back(nums2[left2]); left2++;
                    }
            }
            while(left1<nums1.size()){

                        ans.push_back(nums1[left1]); left1++;
            }
            while(left2<nums2.size()){

                        ans.push_back(nums2[left2]); left2++;
            }
            return ans;

        }
    };