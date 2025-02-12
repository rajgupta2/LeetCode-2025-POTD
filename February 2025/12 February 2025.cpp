/*
Max Sum of a Pair With Equal Sum of Digits
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
*/
class Solution {
    public:
        void addAllSumDigit(vector<int>& arr,unordered_map<int,vector<int>> &mp){
            int n=arr.size();
            for(int i=0;i<n;i++){
              int sumOfDigit=0;
              int num=arr[i];
              while(num>0){
                int digit=num%10;
                num/=10;
                sumOfDigit+=digit;
              }
              //if(mp.find(sum)==mp.end()) mp[sum]={};
              mp[sumOfDigit].push_back(i);
            }
        }
        int maximumSum(vector<int>& arr) {
            //sum,vector<int> of indexs
            unordered_map<int,vector<int>> mp;
            addAllSumDigit(arr,mp);
            int maxi=-1;
            for(auto it:mp){
                int sum=it.first;
                vector<int> index=it.second;
                if(index.size()==1) continue;
                int lar=INT_MIN;
                int sLar=-1;
                for(int i=0;i<index.size();i++){
                    if(lar<arr[index[i]]){
                        sLar=lar;
                        lar=arr[index[i]];
                    }else if(sLar<arr[index[i]] && lar!=arr[index[i]]){
                        sLar=arr[index[i]];
                    }
                }
                if(sLar==INT_MIN) sLar=lar;
                maxi=max(maxi,lar+sLar);
            }
            return maxi;

        }
    };