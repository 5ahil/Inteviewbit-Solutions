/*Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void fun(int&k,TreeNode*A,int B,int&l){
    if(!A){return ;}
    fun(k,A->left,B,l);
    k=k+1;
    if(k==B){
        l=A->val;
        return ;
        
    }
    
    fun(k,A->right,B,l);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int k=0;
    int l; fun(k,A,B,l);
    //cout<<"Again "<<l;
    return l;
}

