/*
You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.
For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.
Note: This code work is not done by me. This is the code that I found from editorial.
*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count[26] = {0};
        for(string &w2 : words2){
            int count2[26] = {0};
            for(char ch : w2){
                count2[ch-'a']++;
                count[ch-'a'] = max(count[ch-'a'], count2[ch-'a']);
            }
        }
        vector<string> res;
        for(string &w1 : words1){
            int count2[26] = {0};
            for(char ch : w1){
                count2[ch-'a']++;
            }
            for(int i = 0; i<=26; i++){
                if(i==26){
                    res.push_back(w1);
                    break;
                }
                if(count[i]>count2[i]) break;
            }
        }
        return res;
    }
};