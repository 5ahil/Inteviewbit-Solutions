/*Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode *c=NULL;
void makeThreads(TreeNode*root,TreeNode**p){
    if(!root)return;
    makeThreads(root->left,p);
    if(*p){
        (*p)->right=root;
    }
    *p=root;
    makeThreads(root->right,p);
}
BSTIterator::BSTIterator(TreeNode *root) {
    c=root;
    while(c&&c->left)c=c->left;
    TreeNode*B=NULL;
    makeThreads(root,&B);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(c)return true;
    return false;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int k=c->val;
    c=c->right;
    return k;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

