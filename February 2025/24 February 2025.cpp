/*
Most Profitable Path in a Tree
There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
If the gate is already open, no price will be required, nor will there be any cash reward.
If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.
*/
class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob,
                               vector<int>& amount) {
            int n = amount.size(), maxIncome = INT_MIN;
            tree.resize(n);
            visited.assign(n, false);
            queue<vector<int>> nodeQueue;
            nodeQueue.push({0, 0, 0});

            // Form tree with edges
            for (vector<int> edge : edges) {
                tree[edge[0]].push_back(edge[1]);
                tree[edge[1]].push_back(edge[0]);
            }

            // Find the path taken by bob to reach node 0 and the times it takes to
            // get there
            findBobPath(bob, 0);

            // Breadth First Search
            visited.assign(n, false);
            while (!nodeQueue.empty()) {
                int sourceNode = nodeQueue.front()[0], time = nodeQueue.front()[1],
                    income = nodeQueue.front()[2];

                // Alice reaches the node first
                if (bobPath.find(sourceNode) == bobPath.end() ||
                    time < bobPath[sourceNode]) {
                    income += amount[sourceNode];
                }

                // Alice and Bob reach the node at the same time
                else if (time == bobPath[sourceNode]) {
                    income += (amount[sourceNode] / 2);
                }

                // Update max value if current node is a new leaf
                if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                    maxIncome = max(maxIncome, income);
                }
                // Explore adjacent unvisited vertices
                for (int adjacentNode : tree[sourceNode]) {
                    if (!visited[adjacentNode]) {
                        nodeQueue.push({adjacentNode, time + 1, income});
                    }
                }

                // Mark and remove current node
                visited[sourceNode] = true;
                nodeQueue.pop();
            }
            return maxIncome;
        }

    private:
        unordered_map<int, int> bobPath;
        vector<bool> visited;
        vector<vector<int>> tree;

        // Depth First Search
        bool findBobPath(int sourceNode, int time) {
            // Mark and set time node is reached
            bobPath[sourceNode] = time;
            visited[sourceNode] = true;

            // Destination for Bob is found
            if (sourceNode == 0) {
                return true;
            }

            // Traverse through unvisited nodes
            for (auto adjacentNode : tree[sourceNode]) {
                if (!visited[adjacentNode]) {
                    if (findBobPath(adjacentNode, time + 1)) {
                        return true;
                    }
                }
            }
            // If node 0 isn't reached, remove current node from path
            bobPath.erase(sourceNode);
            return false;
        }
    };