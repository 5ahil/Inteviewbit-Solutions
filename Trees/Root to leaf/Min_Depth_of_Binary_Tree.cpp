/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(!A)return 0;
    if(!A->left&&!A->right)return 1;
    if(!A->left&&A->right) return 1+Solution::minDepth( A->right);
    if(A->left&&!A->right)return 1+Solution::minDepth( A->left);
    if(A->left&&A->right) return 1+min(Solution::minDepth( A->left),Solution::minDepth( A->right));
}

