/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.*/
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A==NULL)return NULL;
    int val=A->label;
    map<RandomListNode*,RandomListNode*>mp;
    RandomListNode*ans=new RandomListNode(val),*ptr=A->next;
    mp[A]=ans;
    RandomListNode*ans1=ans;
    while(ptr)
    {
        int val=ptr->label;
        RandomListNode*newnode=new RandomListNode(val);
        mp[ptr]=newnode;
        ans1->next=newnode;
        ans1=ans1->next;
        ptr=ptr->next;
    }
    ptr=A;ans1=ans;
    while(ptr)
    {
        if(mp.find(ptr->random)!=mp.end())
        {
            ans1->random=mp[ptr->random];
        }
        else
        ans1->random=NULL;
        ptr=ptr->next;
        ans1=ans1->next;
        
    }
    return ans;
}

