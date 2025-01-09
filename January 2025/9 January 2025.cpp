/*
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(int i=0;i<words.size();i++){
            if(stringMatch(words[i],pref)) res++;
        }
        return res;
    }
private:
    bool stringMatch(string str,string pref){
        if(str.size()<pref.size()) return false;
        for(int i=0;i<pref.size();i++){
            if(str[i]!=pref[i]) return false;
        }
        return true;
    }
};