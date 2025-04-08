//Bridge in a Graph
class Solution {
    public:
      void dfs(vector<vector<int>> &adj, int c, vector<bool> &visited) {
      visited[c] = true;
      for (auto i : adj[c]) {
          if (!visited[i])
              dfs(adj, i, visited);
      }
  }

  // Construct adjacency list without the edge (c, d)
  vector<vector<int>> constructadj(int V,
                vector<vector<int>> &edges, int c, int d) {
      vector<vector<int>> adj(V);
      for (auto &edge : edges) {

          // Skip the edge (c, d) or (d, c)
          if ((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c))
              continue;

          adj[edge[0]].push_back(edge[1]);
          adj[edge[1]].push_back(edge[0]);
      }
      return adj;
  }

  // Check if the edge (c, d) is a bridge
  bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
      vector<vector<int>> adj = constructadj(V, edges, c, d);

      vector<bool> visited(V, false);
      dfs(adj, c, visited);

      // if d is not reachable from c → bridge
      return !visited[d];
  }

  };
