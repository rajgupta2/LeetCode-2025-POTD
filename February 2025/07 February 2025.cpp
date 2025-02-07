/*
Find the Number of Distinct Colors Among the Balls
You are given an integer limit and a 2D array queries of size n x 2.
There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
*/
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballsWithColor;
        unordered_map<int,int> color;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int col=queries[i][1];
            if(ballsWithColor.find(ball)==ballsWithColor.end()){
                ballsWithColor[ball]=col;
                color[col]++;
            }else{
                //remove the already color value
                color[ballsWithColor[ball]]--;
                if(color[ballsWithColor[ball]]==0)
                color.erase(ballsWithColor[ball]);
                ballsWithColor[ball]=col;
                color[col]++;
            }
            ans.push_back(color.size());
        }
        return ans;
    }
};