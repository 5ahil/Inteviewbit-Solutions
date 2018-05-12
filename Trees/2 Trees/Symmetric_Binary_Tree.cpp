/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* invert(TreeNode*A){
    if(!A)return A;
    TreeNode*l=invert(A->left);
    TreeNode*r=invert(A->right);
    A->left=r;
    A->right=l;
    return A;
}
int is_iden(TreeNode*A,TreeNode*B){
    if(!A&&!B)return 1;
    if(!A&&B||A&&!B||A->val!=B->val)return 0;
    return is_iden(A->left,B->left)&&is_iden(A->right,B->right);
}
int Solution::isSymmetric(TreeNode* A) {
    if(!A)return 1;
    invert(A->right);
    return is_iden(A->left,A->right);
}

