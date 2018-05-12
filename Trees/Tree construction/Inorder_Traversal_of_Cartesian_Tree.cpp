/*	Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode*util(int root,vector<int>&A,vector<int>&lc,vector<int>&rc){
    if(root==-1)return NULL;
    TreeNode *t= new TreeNode(A[root]);
    t->left=util(lc[root],A,lc,rc);
    t->right=util(rc[root],A,lc,rc);
    return t;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    vector<int>p(A.size(),-1);
    vector<int>lc(A.size(),-1);
    vector<int>rc(A.size(),-1);
    int root=0;
    for(int i=1;i<A.size();i++){
        int before_i=i-1;
        while(A[before_i]<=A[i]&&root!=before_i){
            before_i=p[before_i];
        }
        if(A[before_i]<=A[i]){
            p[root]=i;
            lc[i]=root;
            root=i;
        }
        else if(rc[before_i]==-1){
            p[i]=before_i;
            rc[before_i]=i;
        }
        else{
            p[rc[before_i]]=i;
            
            lc[i]=rc[before_i];
            rc[before_i]=i;
            p[i]=before_i;
            /*
            if (arr[last] <= arr[i])
        {
            parent[root] = i;
            leftchild[i] = root;
            root = i;
        }
 
        // Just insert it
        else if (rightchild[last] == -1)
        {
            rightchild[last] = i;
            parent[i] = last;
            leftchild[i] = -1;
        }
 
            parent[rightchild[last]] = i;
            leftchild[i] = rightchild[last];
            rightchild[last] = i;
            parent[i] = last;*/
        }
    }
    
    return util(root,A,lc,rc);
}

