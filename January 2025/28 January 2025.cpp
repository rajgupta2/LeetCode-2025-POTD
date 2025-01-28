/*
Maximum Number of Fish in a Grid
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:
Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
*/
class Solution {
public:
    int doSomething(vector<vector<int>>& grid, vector<vector<int>>& visited,
                     int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0 || visited[row][col]==1) {
            return 0;
    }
                        visited[row][col]=1;
                        int ans=grid[row][col];
                        int dx[]={0,-1,0,1};
                        int dy[]={-1,0,1,0};
                        for(int i=0;i<4;i++){
                            int nrow=row+dx[i];
                            int ncol=col+dy[i];
                            ans+=doSomething(grid,visited,nrow,ncol);
                        }
                        return ans;

                     }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        int maxFish=0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && visited[i][j] == -1) {
                    maxFish=max(maxFish,doSomething(grid,visited,i,j));
                }
            }
        }
        return maxFish;
    }
};