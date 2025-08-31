// Last updated: 8/31/2025, 10:50:18 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diffH(TreeNode* root)
    {
        if (root==NULL) return 0;
        int Lh=diffH(root->left);
        int Rh=diffH(root->right);
        if (Lh==-1 || Rh==-1) return -1;
        if (abs(Lh-Rh)>1) return -1;
        return 1+max(Rh,Lh);
    }
    bool isBalanced(TreeNode* root) {
        if (diffH(root)==-1) return false;
        return true;
    }
};