/*Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void rev(ListNode*head,ListNode*prev,ListNode*curr)
 {
     if(!curr)
     {
         
         head->next=prev;
         return ;
     }
     ListNode*Next=curr->next;
     curr->next=prev;
     rev(head,curr,Next);
     
 }
int Solution::lPalin(ListNode* A) {
    if(!A||!A->next)
    {
        return 1;
    }
    ListNode*slow,*fast,*pp;
    slow=A;
    fast=A->next;
    while(fast)
    {
        fast=fast->next;
        if(!fast)break;
        slow=slow->next;
        fast=fast->next;
        //if(!fast->next)break;
    }
    
    pp=slow->next;
    if(slow->next->next)
    rev(slow,NULL,pp);
    fast=slow->next;
    slow=A;
    while(fast)
    {
        if(slow->val!=fast->val)return 0;fast=fast->next;
        slow=slow->next;
    }
    return 1;
}
