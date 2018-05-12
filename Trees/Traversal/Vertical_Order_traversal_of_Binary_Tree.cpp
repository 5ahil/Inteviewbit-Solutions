/*Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * #include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int val;
    struct node*left,*right;
}TreeNode;
TreeNode*mn(int d){
    TreeNode*t=new TreeNode();
    t->val=d;
    t->left=t->right=NULL;
    return t;
}
void in(TreeNode*A){
    if(!A)return ;
    in(A->left);
    cout<<A->val<<",";
    in(A->right);
}
void zig(TreeNode*A){
    stack<TreeNode*>s1;
    stack<TreeNode*>s2;
    s1.push(A);bool turn=true;
    while(!s1.empty()||!s2.empty()){
        TreeNode*temp;
        while(!s1.empty()){
            temp=s1.top();
            s1.pop();
            cout<<temp->val<<",";
            if(temp->left)s2.push(temp->left);
            if(temp->right)s2.push(temp->right);
        }
        while(!s2.empty()){
            temp=s2.top();
            s2.pop();
            cout<<temp->val<<",";
            if(temp->right)s1.push(temp->right);
            if(temp->left)s1.push(temp->left);
        }
    }
}
int main(){
    TreeNode*root=mn(1);
    root->left=mn(2);
    root->right=mn(3);
    root->left->left=mn(4);
    root->left->right=mn(5);
    root->right->left=mn(6);
    root->right->right=mn(7);
    in(root);cout<<endl;
    zig(root);
}
 */
 void hash_it(int idx,map<int,vector<int>>&mp,TreeNode*root){
    if(!root)return;
    mp[idx].push_back(root->val);
    hash_it(idx-1,mp,root->left);
    hash_it(idx+1,mp,root->right);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>>ans;
    if(!A)return ans;
    map<int,vector<int>>mp;
    
    queue<pair<TreeNode*,int>>q;
    q.push(make_pair(A,0));
    while(!q.empty()){
        pair<TreeNode*,int>temp=q.front();
        mp[temp.second].push_back(temp.first->val);
        q.pop();
        if(temp.first->left){
            q.push(make_pair(temp.first->left,temp.second-1));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right,temp.second+1));
        }
        
    }
    map<int,vector<int>>::iterator i;
    for(i=mp.begin();i!=mp.end();i++){
        ans.push_back(i->second);
    }
    return ans;
}

