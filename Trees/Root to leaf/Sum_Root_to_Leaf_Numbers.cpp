/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int f(TreeNode*A,int sum){
    
    if(!A)return 0;
    sum=A->val+sum*10;
    sum%=1003;
	if(!A->left&&!A->right)return sum;
	return (f(A->left,sum)+f(A->right,sum))%1003;
    
}
int Solution::sumNumbers(TreeNode* A) {
    if(!A)return 0;
    int sum=0;
    return f(A,sum);
}

