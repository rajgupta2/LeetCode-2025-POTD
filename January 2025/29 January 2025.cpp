/*
Redundant Connection
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/
class Solution {
private:
    int cycleStart=-1;
public:
    void DFS(int src, vector<bool>& visited, vector<vector<int>> adjList,
             vector<int>& parent) {
        visited[src] = true;
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                parent[adj] = src;
                DFS(adj, visited, adjList,parent);
                // if the adj node is already visited and if the parent of adj
                // node is not the src node means the adj node is alredy visited
                // by any other node showing that there is an cycle.
            } else if (adj != parent[src] && cycleStart == -1) {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<vector<int>> adjList(N + 1, vector<int>(0, {}));
        for (auto e : edges) {
            int src = e[0];
            int tar = e[1];
            adjList[src].push_back(tar);
            adjList[tar].push_back(src);
        }
        vector<bool> visited(N + 1, false);
        vector<int> parent(N + 1, -1);
        DFS(1, visited, adjList, parent);
        unordered_map<int,int> cycleNodes;
        int node=cycleStart;
        do {
            cycleNodes[node] = 1;
            node = parent[node];
        } while (node != cycleStart);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleNodes[edges[i][0]] && cycleNodes[edges[i][1]]) {
                return edges[i];
            }
        }

        return {};
    }
};