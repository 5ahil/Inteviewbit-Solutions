/*Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*>s1,s2;
    int d1=0,d2=0;TreeNode*i1=A,*i2=A;TreeNode*v1,*v2;
    while(true){
        
        while(d1==0){
            if(i1){
                s1.push(i1);
                i1=i1->left;
            }
            else{
                if(!s1.empty()){
                    v1=s1.top();
                    i1=v1->right;
                    s1.pop();
                    d1=1;
                }
                else{
                    d1=1;
                }
            }
        }
        while(d2==0){
            if(i2){
                s2.push(i2);
                i2=i2->right;
            }
            else{
                if(!s2.empty()){
                    v2=s2.top();
                    i2=v2->left;
                    s2.pop();
                    d2=1;
                }
                else{
                    d2=1;
                }
            }
        }
        if(v1!=v2&&v1->val+v2->val==B)return 1;
        else if(v1->val+v2->val<B){
            d1=0;
        }
        else d2=0;
        if(v1==v2||v1->val>v2->val)return 0;
    }
}

