/*
Special Array I
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.
*/
class Solution {
public:
    bool isArraySpecial(vector<int>& num) {
        int n=num.size();
        if(n==1) return true;
        //check for 0th & 1th index
        bool res=((num[0]%2==0 && num[1]%2!=0) || (num[1]%2==0 && num[0]%2!=0) )? true:false;
        if(res==false) return false;
        for(int i=1;i<n-1;i++){
            int a=num[i];
            int b=num[i+1];
            bool r=((a%2==0 && b%2!=0) || (b%2==0 && a%2!=0) )? true:false;
            if(r==false) return false;
        }
        bool res2=((num[n-2]%2==0 && num[n-1]%2!=0) || (num[n-1]%2==0 && num[n-2]%2!=0) )? true:false;
        if(res2==false) return false;
        return true;
    }
};
