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
   int steps=0;

   int ok (TreeNode*root){
    if(root==NULL)return 0;
    int l=ok(root->left);
    int r=ok(root->right);
    steps+=abs(l)+abs(r);
    return(l+r+root->val-1);
   }

   int distributeCoins(TreeNode* root){
    ok(root);
    return steps;
   }
};