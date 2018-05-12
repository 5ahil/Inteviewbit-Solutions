/*Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

Seen this question in a real interview before*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flaa(TreeNode*A){
	if(!A)return;
	static TreeNode*prev=NULL;
	TreeNode*left=A->left;
	TreeNode*right=A->right;
	if(prev){
		prev->left=NULL;
		prev->right=A;
	}
	prev=A;
	flaa(left);
	flaa(right);
}
TreeNode* Solution::flatten(TreeNode* A) {
    flaa(A  );
    return A;
}
	
