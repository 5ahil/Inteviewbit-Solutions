/*Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void zig(TreeNode*A,vector<vector<int>>&ans){
    stack<TreeNode*>s1;
    stack<TreeNode*>s2;
    s1.push(A);bool turn=true;
    vector<int>aa;
    while(!s1.empty()||!s2.empty()){
        TreeNode*temp;
        while(!s1.empty()){
            temp=s1.top();
            s1.pop();
            aa.push_back(temp->val);
            if(temp->left)s2.push(temp->left);
            if(temp->right)s2.push(temp->right);
        }
        if(aa.size()>0)
        ans.push_back(aa);
        aa.clear();
        while(!s2.empty()){
            temp=s2.top();
            s2.pop();
            aa.push_back(temp->val);
            if(temp->right)s1.push(temp->right);
            if(temp->left)s1.push(temp->left);
        }
        if(aa.size()>0)
        ans.push_back(aa);
        aa.clear();
    }
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>>ans;
    zig(A,ans);
    return ans;
}

