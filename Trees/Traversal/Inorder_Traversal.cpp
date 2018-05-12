/*Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
        vector<int> sol;
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    bool done = 0;
    
    while(!done){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(!st.empty()){
                curr = st.top();
                int val = curr->val;
                sol.push_back(val);
                curr = curr->right;
                st.pop();
            }
            else{
                done = 1;
            }
        }
    }
    
    return sol;
}

