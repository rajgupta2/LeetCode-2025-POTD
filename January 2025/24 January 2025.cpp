/*
Find Eventual Safe States
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};