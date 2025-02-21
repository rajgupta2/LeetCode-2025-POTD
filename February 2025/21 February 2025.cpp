/*
Find Elements in a Contaminated Binary Tree
Given a binary tree with the following rules:
root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
*/
class FindElements {
    unordered_set<int> seen;

public:
    FindElements(TreeNode* root) { bfs(root); }

    bool find(int target) { return seen.find(target) != seen.end(); }

private:
    void bfs(TreeNode* root) {
        queue<TreeNode*> queue;
        root->val = 0;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* currentNode = queue.front();
            queue.pop();
            // visit currentNode by adding its recovered value to the set
            seen.insert(currentNode->val);
            if (currentNode->left) {
                currentNode->left->val = currentNode->val * 2 + 1;
                queue.push(currentNode->left);
            }
            if (currentNode->right) {
                currentNode->right->val = currentNode->val * 2 + 2;
                queue.push(currentNode->right);
            }
        }
    }
};