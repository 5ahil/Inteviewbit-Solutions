/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode*fun(int l,int h,const vector<int>&A){
    if(l>h){
        return NULL;
    }
    int mid=(l+h)/2;
    TreeNode*root=new TreeNode(A[mid]);//(A[mid]);//
    
    root->left=fun(l,mid-1,A);
    root->right=fun(mid+1,h,A);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    //TreeNode*root=NULL;
    return fun(0,A.size()-1,A);
}

