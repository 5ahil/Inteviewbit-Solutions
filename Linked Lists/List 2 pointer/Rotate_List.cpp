/*Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL*/
.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode*p1,*p2,*p3=NULL;
    p1=p2=A;int k=0;
    while(p1)
    {
        p1=p1->next;
        k++;
    }
    if(k!=1)
    B=B%k;
    if(B==0)return A;
    p1=A;
    while(p1&&B--)
    {
        p1=p1->next;
        k++;
    }
    if(!p1)return A;
    while(p1->next)
    {
        p1=p1->next;
        p2=p2->next;
    }
    p3=p2->next;
    p2->next=NULL;
    p1->next=A;
    return p3;
}
