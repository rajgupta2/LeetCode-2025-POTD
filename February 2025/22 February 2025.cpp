/*
Recover a Tree From Preorder Traversal
We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.
*/
class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            int index = 0;
            return helper(traversal, index, 0);
        }

    private:
        TreeNode* helper(const string& traversal, int& index, int depth) {
            if (index >= traversal.size()) return nullptr;

            // Count the number of dashes
            int dashCount = 0;
            while (index + dashCount < traversal.size() &&
                   traversal[index + dashCount] == '-') {
                dashCount++;
            }

            // If the number of dashes doesn't match the current depth, return null
            if (dashCount != depth) return nullptr;

            // Move index past the dashes
            index += dashCount;

            // Extract the node value
            int value = 0;
            while (index < traversal.size() && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            // Create the current node
            TreeNode* node = new TreeNode(value);

            // Recursively build the left and right subtrees
            node->left = helper(traversal, index, depth + 1);
            node->right = helper(traversal, index, depth + 1);

            return node;
        }
    };