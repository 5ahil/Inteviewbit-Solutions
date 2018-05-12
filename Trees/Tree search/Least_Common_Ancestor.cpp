/*Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
Seen this question */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void mm(TreeNode*A,int B,bool&b,int C,bool&c){
    if(!A)return ;
    if(A->val==B)b=true;
    if(A->val==C)c=true;
    mm(A->left,B,b,C,c);
    mm(A->right,B,b,C,c);
}
bool find(TreeNode*A,int B,int C){
    bool b=false,c=false;
    mm(A,B,b,C,c);
    
    return b&&c;
}

TreeNode* f(TreeNode*A,int B,int C){
    if(!A)return NULL;
    if(A->val==B||A->val==C)return A;
    TreeNode*leftwala=f(A->left,B,C);
    TreeNode*rightwala=f(A->right,B,C);
    if(leftwala&&rightwala)return A;
    return leftwala?leftwala:rightwala;
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool yes=find(A,B,C);
    return yes?f(A,B,C)->val:-1;
}

