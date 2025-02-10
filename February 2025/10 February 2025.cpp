/*
Clear Digits
You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.
*/
class Solution {
    public:
        void  removeCurrentDigitPlusLeftChar(int ind,vector<int> &digitFind){
            digitFind[ind]=0;
            for(int i=ind-1;i>=0;i--){
                if(digitFind[i]==-1)
                {
                    digitFind[i]=0;
                    break;
                }
            }
        }

        string clearDigits(string s) {
            int n=s.size();
            string newstr="";
            vector<int> digitFind(n,-1);
            for(int i=0;i<s.size();i++){
                if(s[i]-'0'>=0 && s[i]-'0'<=9)
                 digitFind[i]=1;
            }
            for(int i=0;i<s.size();i++){
                if(digitFind[i]==1){
                    removeCurrentDigitPlusLeftChar(i,digitFind);
                }
            }
            for(int i=0;i<s.size();i++){
                if(digitFind[i]==-1){
                    newstr+=s[i];
                }
            }
            return newstr;
        }
    };