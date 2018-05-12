/*Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode*p1,*p2,*p3,*p4,*head;
    if(A==NULL)return B;
    if(B==NULL)return A;
    if(A->val<B->val)
    {
        head=A;
        A=A->next;
    }
    else{
        head=B;
        B=B->next;
    }
    p1=head;
    while(A&&B)
    {
        if(A->val<B->val)
        {
            p1->next=A;
            p1=p1->next;
            A=A->next;
        }
        else
        {
            p1->next=B;
            p1=p1->next;
            B=B->next;
        }
    }
    if(A)
    {
        p1->next=A;
    }
    else
    {
        p1->next=B;
    }
    return head;
}
