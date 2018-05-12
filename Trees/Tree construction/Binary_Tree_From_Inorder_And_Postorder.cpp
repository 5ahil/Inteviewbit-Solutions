/*Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
    if(*idx<0||l>r)return NULL;
   // cout<<"searching for:"<<B[*idx]<<endl;
    TreeNode*newnode=new TreeNode(B[*idx]);
    int root_loc=find(A,l,r,B[*idx]);
    (*idx)--;
    newnode->right=rec(A,B,idx,root_loc+1,r);
    newnode->left=rec(A,B,idx,l,root_loc-1);
    return newnode;
}
TreeNode*f(vector<int>&A,vector<int>&B){
    
    TreeNode*nn;//=makeNode()
    int idx=B.size()-1;
    nn=rec(A,B,&idx,0,A.size()-1);
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return f(A,B);
}

