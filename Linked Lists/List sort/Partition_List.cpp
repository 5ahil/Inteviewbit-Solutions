/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* h, int k) {
    if(h==NULL||h->next==NULL)
    {
        return h;
    }
    //decide head
    ListNode*p1,*p2,*p3=h;
    p1=h;
    
    if(h->val>=k)
    {
        while(p1->next&&p1->next->val>=k)
        {
            p1=p1->next;
        }
        if(!p1->next)return h;
        p3=p1->next;
        p1->next=p1->next->next;
        p3->next=h;
        h=p3;
    }
    else
    {
        while(p3->next&&p3->next->val<k)
        {
            p3=p3->next;
        }
        if(!p3->next)return h;
        p1=p3->next;
    }
    while(p1->next&&p3)
    {
        if(p1->next->val<k)
        {
            ListNode*np3=p3->next,*np1=p1->next;
            p1->next=p1->next->next;
            p3->next=np1;
            np1->next=np3;
            
            p3=p3->next;
        }
        else p1=p1->next;
    }
    return h;
}
