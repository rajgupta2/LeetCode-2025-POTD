/*
Unique Length-3 Palindromic Subsequences
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
A palindrome is a string that reads the same forwards and backwards.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;
        for (char ch : s) {
            st.insert(ch);
        }
        int ans=0;
        for (char letter : st) {
            int i = -1, j = -1;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1)
                        i = k;
                    j = k;
                }
            }
            unordered_set<char> between;
            for(int k=i+1;k<j;k++){
                between.insert(s[k]);
            }
            ans += between.size();

        }
        return ans;
    }
};