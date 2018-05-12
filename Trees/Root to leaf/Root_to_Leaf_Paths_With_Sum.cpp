/*Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]*/void find(TreeNode *root,int sum,vector<int> &path,int &pathlen,vector<vector<int> >&res)
 {
     if(root==NULL)
     return;
     path[pathlen]=root->val;
     pathlen++;
     int remainsum = sum-root->val;
     if(root->left==NULL&&root->right==NULL&&remainsum==0)
    {    res.push_back(path);
      //  flag=1;
    }
     else
     {
         find(root->left,remainsum,path,pathlen,res);
        find(root->right,remainsum,path,pathlen,res);
     }
 }
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int> > res(300);
   
    vector<int> path;
    int pathlen = 0;
    
    
    find(A,B,path,pathlen,res);
    int i=0;
    while(!res[i].empty())
    i++;
    res.resize(i);
    
    return res;
}
