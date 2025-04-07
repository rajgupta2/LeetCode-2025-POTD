//Partition Equal Subset Sum
class Solution {
    public:
        bool subset(int ind,int sum,vector<int>& nums,vector<vector<int>> &dp){
            if(sum<0) return false;
            if(sum==0) return true;
            if(ind==0) return sum==nums[0];
            if(dp[ind][sum]!=-1) return dp[ind][sum];
            bool pick=false;
            pick=subset(ind-1,sum-nums[ind],nums,dp);
            if(pick) return dp[ind][sum]=true;
            bool notpick=subset(ind-1,sum,nums,dp);
            return dp[ind][sum]=pick | notpick;
        }
        bool canPartition(vector<int>& nums) {
            int sum=accumulate(nums.begin(),nums.end(),0);
            if(sum%2!=0) return false;
            vector<vector<int>> dp(nums.size(),vector<int> (sum/2+1,-1));
            return subset(nums.size()-1,sum/2,nums,dp);
        }
    };