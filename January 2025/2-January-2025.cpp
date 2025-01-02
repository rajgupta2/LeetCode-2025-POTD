/*
Count Vowel Strings in Ranges
You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
*/
class Solution {
public:
    bool isVowelString(string word){
        int last=word.size() -1;
        char start=word[0];
        char end=word[last];

        if( (start=='a' || start=='i' || start=='e' || start=='o' || start=='u')
          && (end=='a' || end=='i' || end=='e' || end=='o' || end=='u') )
           return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> cntvowelstring(n+1,0);

        for(int i=0;i<n;i++){
            if(isVowelString(words[i]))
             cntvowelstring[i+1]=1+cntvowelstring[i];
            else
             cntvowelstring[i+1]=cntvowelstring[i];
        }
        vector<int> ans;
        for(auto it:queries){
            int left=it[0];
            int right=it[1];
            ans.push_back(cntvowelstring[right+1]-cntvowelstring[left]);
        }
        return ans;
    }
};
