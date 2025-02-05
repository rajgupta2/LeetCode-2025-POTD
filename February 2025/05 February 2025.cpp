/*
Check if One String Swap Can Make Strings Equal
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;
        int ind1=-1;
        int ind2=-1;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(ind1==-1) ind1=i;
                else ind2=i;
            }
            if(cnt>=3) return false;
        }
        if(ind2==-1) return false;
        if(s1[ind1]==s2[ind2] && s1[ind2]==s2[ind1]) return true;
        return false;
    }
};