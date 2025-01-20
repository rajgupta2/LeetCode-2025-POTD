/*
First Completely Painted Row or Column
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
Return the smallest index i at which either a row or a column will be completely painted in mat.
*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        //hash array of element with (row,col)

        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>> hash(m*n+1,{-1,-1});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hash[mat[i][j]]={i,j};
            }
        }
        //each row contains m element
        vector<int> rows(n,m);
        //each col contains n element
        vector<int> cols(m,n);

        for(int i=0;i<m*n;i++){
            auto p=hash[arr[i]];
            int row=p.first;
            int col=p.second;
            rows[row]--;
            if(rows[row]==0) return i;
            cols[col]--;
            if(cols[col]==0) return i;
        }
        //dummy return
        return -1;
    }
};