/*
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int size=s.size();
        vector<int> diffArray(size,0);
        int n=shifts.size();
        for(int i=0;i<n;i++){
            int startInd=shifts[i][0];
            int endInd=shifts[i][1];
            int direction=shifts[i][2];
                if(direction==1){
                    //forward
                    diffArray[startInd]++;
                    if(endInd+1<size) diffArray[endInd+1]--;
                }else{
                    //backward
                   diffArray[startInd]--;
                    if(endInd+1<size) diffArray[endInd+1]++;
                }
        }
        string res(size,' ');
        int numOfShift=0;
        for(int i=0;i<size;i++){
            numOfShift = (numOfShift + diffArray[i]) %26;
            if (numOfShift < 0)
                numOfShift +=26;
            res[i] = 'a' + (s[i] - 'a' + numOfShift) % 26;
        }
        return res;
    }
};