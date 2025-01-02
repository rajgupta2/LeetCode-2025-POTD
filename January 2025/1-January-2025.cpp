/*
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
*/
class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int one=0;
        for(char ch:s){
            if(ch=='1')
             one++;
        }
        int leftCntZero=0,leftCntOne=0;
        int ans=0;
        for(int i=0;i<=n-2;i++){
          if(s[i]=='0') leftCntZero++;
          else leftCntOne++;
          ans=max(ans,leftCntZero+(one-leftCntOne));
        }
        return ans;
    }
};