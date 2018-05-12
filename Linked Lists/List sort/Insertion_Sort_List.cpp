/*Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* h) {
    if(h==NULL||h->next==NULL)
    {
        return h;
    }
    //decide head
    ListNode*p1=h,*p2=h,*p3=h;
    if(p2->next==NULL)return h;
    while(p2->next)
    {
        p1=h;//cout<<"here2\n"<<"p2="<<p2->val<<endl;
        if(p2->next->val<=p1->val)
        {
            
            p3=p2->next->next;
            ListNode*np2=p2->next;
            p2->next=p3;
            np2->next=h;
            h=np2;
            continue;
        }
        while(p1->next!=p2->next&& p1->next->val<=p2->next->val)
        {
            p1=p1->next;//cout<<"here3\n";
        }
        if(p1->next==p2->next)
        {
            p2=p2->next;
            continue;
        }
        p3=p2->next->next;
        ListNode*np2=p2->next,*np1=p1->next;
        p2->next=p3;
        p1->next=np2;
        np2->next=np1;
        
        
    }
    
    return h;
}
