/*Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int find(vector<int>&A,int l,int h,int key){
    while(l<=h){
        if(A[l]==key)return l;
        
        l++;
    }
}
TreeNode*rec(vector<int>&A,vector<int>&B,int *idx,int l,int r){
    if(l>r)return NULL;
    TreeNode*newnode=new TreeNode(B[*idx]);
    
    int mid=find(A,l,r,B[*idx]);
    (*idx)++;
    newnode->left=rec(A,B,idx,l,mid-1);
    newnode->right=rec(A,B,idx,mid+1,r);
    return newnode;
}
TreeNode*f(vector<int>&A,vector<int>&B){
    
    TreeNode*nn;
    int idx=0;
    nn=rec(A,B,&idx,0,A.size()-1);
    return nn;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return f(B,A);
}

