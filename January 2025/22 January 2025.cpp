/*
Map of Highest Peak
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:
The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.
Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
*/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> cellQueue;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> cellHeight(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    cellQueue.push({i, j});
                    cellHeight[i][j] = 0;
                }
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int heightOfNextLayer = 1;
        while (!cellQueue.empty()) {
            int size = cellQueue.size();

            for (int i = 0; i < size; i++) {
                auto currentCell = cellQueue.front();
                cellQueue.pop();
                for (int d = 0; d < 4; d++) {
                    pair<int, int> neighborCell = {currentCell.first + dx[d],
                                                   currentCell.second + dy[d]};

                    // Check if the neighbor is valid and unprocessed
                    if (isValidCell(neighborCell,n,m) &&
                        cellHeight[neighborCell.first][neighborCell.second] ==
                            -1) {
                        cellHeight[neighborCell.first][neighborCell.second] =
                            heightOfNextLayer;
                        cellQueue.push(neighborCell);
                    }
                }
            }
             heightOfNextLayer++;
        }
        return cellHeight;
    }
    bool isValidCell(pair<int, int> cell, int rows, int columns) {
        return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
               cell.second < columns;
    }
};