/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL)return A;
    ListNode*ptr1=A,*ptr2=A->next;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        while(ptr2!=NULL&&ptr1->val==ptr2->val)
        {
            ptr2=ptr2->next;
        }
        ptr1->next=ptr2;
        ptr1=ptr1->next;
        if(ptr2!=NULL)
        ptr2=ptr2->next;
    }
    return A;
}
