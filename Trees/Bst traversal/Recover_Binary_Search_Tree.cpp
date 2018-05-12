/*Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void f(TreeNode*A,TreeNode** prev,vector<int>&v){
    if(!A)return;
    f(A->left,prev,v);
    if(*prev!=NULL&&(*prev)->val>A->val){
        if(v.size()==0){
            v.push_back((*prev)->val);
            v.push_back(A->val);
        }
        else{
            v[1]=A->val;
        }
    }
    *prev=A;
    f(A->right,prev,v);
    
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int>v;
    TreeNode*prev=NULL;
    f(A,&prev,v);
    sort(v.begin(),v.end());
    return v;
}
          

