/*
Construct Binary Tree from Preorder and Postorder Traversal
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.
*/
class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder,
                                    vector<int>& postorder) {
            int numOfNodes = preorder.size();

            // Create the index array of `postorder`
            vector<int> indexInPostorder(numOfNodes + 1);
            for (int index = 0; index < numOfNodes; index++) {
                // Store the index of the current element
                indexInPostorder[postorder[index]] = index;
            }

            return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostorder);
        }

    private:
        // Helper function to construct the tree recursively
        TreeNode* constructTree(int preStart, int preEnd, int postStart,
                                vector<int>& preorder,
                                vector<int>& indexInPostorder) {
            // Base case: If there are no nodes to process, return NULL
            if (preStart > preEnd) return NULL;

            // Base case: If only one node is left, return that node
            if (preStart == preEnd) {
                return new TreeNode(preorder[preStart]);
            }

            // The left child root in preorder traversal (next element after root)
            int leftRoot = preorder[preStart + 1];

            // Calculate the number of nodes in the left subtree by searching in
            // postorder
            int numOfNodesInLeft = indexInPostorder[leftRoot] - postStart + 1;

            TreeNode* root = new TreeNode(preorder[preStart]);

            // Recursively construct the left subtree
            root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                    postStart, preorder, indexInPostorder);

            // Recursively construct the right
            root->right = constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                                        postStart + numOfNodesInLeft, preorder,
                                        indexInPostorder);

            return root;
        }
    };