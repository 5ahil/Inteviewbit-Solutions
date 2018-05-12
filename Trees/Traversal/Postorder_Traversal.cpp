/*Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int>ans;
    stack<TreeNode*>st;
    TreeNode*c=A;
    while(true){
        while(c){
            st.push(c);
            c=c->left;
        }
        if(st.empty())break;
        c=st.top();
        st.pop();
        if(!st.empty()&&c==st.top()){
            ans.push_back(c->val);
            st.pop();//cout<<"here\n";
            c=NULL;
            continue;
        }
        st.push(c);
        st.push(c);
        c=c->right;
    }
    return ans;
}

