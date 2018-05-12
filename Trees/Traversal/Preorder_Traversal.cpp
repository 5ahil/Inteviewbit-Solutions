/*Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*>st;
    vector<int>ans;
    TreeNode*c=A;
    while(true){
        while(c){
            ans.push_back(c->val);
            st.push(c);
            c=c->left;
        }
        if(st.empty())break;
        c=st.top();
        c=c->right;
        st.pop();
    }
    return ans;
}

