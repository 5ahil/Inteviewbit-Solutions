/*Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode*ptr1,*ptr2;
    ptr1=A;ptr2=A;
    while(ptr1!=NULL&&B>0)
    {
        ptr1=ptr1->next;B--;
    }
    
    if(ptr1==NULL)
    {
        A=A->next;
        return A;
    }
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr2->next=ptr2->next->next;
    return A;
}
