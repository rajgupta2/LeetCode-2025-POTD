/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.size(),0);
        int n=boxes.size();
        int ballsToLeft=0,movesToLeft=0;
        int ballToright=0,movesToright=0;
        for(int i=0;i<boxes.size();i++){
            //Left Pass
            answer[i]+=movesToLeft;
            ballsToLeft+=boxes[i]-'0';
            movesToLeft+=ballsToLeft;

            //Right Pass
            answer[n-1-i]+=movesToright;
            ballToright+=boxes[n-1-i]-'0';
            movesToright+=ballToright;
        }
        return answer;
    }
};