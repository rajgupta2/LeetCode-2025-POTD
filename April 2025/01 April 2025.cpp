/*
Solving Questions With Brainpower
*/
class Solution {
    public:
        long long solve(int ind,vector<vector<int>>& questions,int n,vector<long long> &dp){
            if(ind>=n) return 0;
            if(dp[ind]!=-1) return dp[ind];
            //choosing
            long long a=questions[ind][0]+solve(ind+questions[ind][1]+1,questions,n,dp);
            //not-choosing
            long long b=solve(ind+1,questions,n,dp);
            return dp[ind]=max(a,b);
        }

        long long mostPoints(vector<vector<int>>& questions) {
            long long maxi=LONG_MIN;
            int n=questions.size();
            vector<long long> dp(n,-1);
            return solve(0,questions,n,dp);
        }
    };