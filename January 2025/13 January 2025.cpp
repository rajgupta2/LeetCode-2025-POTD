/*
Minimum Length of String After Operations
You are given a string s.
You can perform the following process on s any number of times:
Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.
*/
class Solution {
public:
    int minimumLength(string s) {
        vector<int> fre(26,0);
        for(char ch:s) fre[ch-'a']++;
        int deleted=0;

        for(int i=0;i<26;i++){
            if(fre[i]==0) continue;
            if(fre[i]%2==0) deleted+=fre[i]-2;
            else deleted+=fre[i]-1;
        }
        return s.size()-deleted;
    }
};