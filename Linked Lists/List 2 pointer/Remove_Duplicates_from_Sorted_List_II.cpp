/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 bool f(ListNode*p2)
 {
     if(p2==NULL||p2->next==NULL||p2->val!=p2->next->val)return true;
     return false;
 }
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode*p1,*p2,*p3=NULL;
    if(!A||!A->next)return A;
    p1=A;
    while(p1)
    {
        int cnt=1;
        while(p1->next&&p1->val==p1->next->val)
        {
            p1=p1->next;cnt++;
        }
        if(cnt==1)
        {
            p3=p1;
            break;
        }
        p1=p1->next;
    }
    
    if(p3==NULL)return NULL;
    p3=p1;
    
    p2=p1->next;
    p1->next=NULL;
    while(p2)
    {
        int cnt=1;
        while(p2->next&&p2->val==p2->next->val)
        {
            p2=p2->next;cnt++;
        }
        if(cnt==1)
        {
            p1->next=p2;
            p1=p1->next;
            p2=p2->next;
            p1->next=NULL;
            continue;
            
        }
        p2=p2->next;
    }
    return p3;
}
