/*Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode*rev(ListNode*h,ListNode*prev)
{
    if(!h||!h->next)
    {
        if(h)
        {
            h->next=prev;
        }
        return h;
    }
    ListNode*nnh=h->next;
    h->next=prev;
    h= rev(nnh,h);
    return h;
}
ListNode*reod(ListNode*h)
{
    if(!h||!h->next||!h->next->next)
    {
        return h;
    }
    ListNode*s=h,*f=h->next;
    while(f)
    {
        f=f->next;
        if(!f)break;
        s=s->next;
        f=f->next;
    }
    f=s->next;
    //print(f);
    f=rev(f,NULL);
    //print(f);
    s->next=NULL;
    
    s=h;//print(s);
    while(s&&f)
    {
        ListNode*ns=s->next,*nf=f->next;
        s->next=f;
        f->next=ns;
        f=nf;
        s=s->next->next;
    }
    return h;
}
ListNode* Solution::reorderList(ListNode* A) {
    return reod(A);
}
