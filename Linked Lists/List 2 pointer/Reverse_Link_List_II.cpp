/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode*tt=NULL;
 ListNode*rev(ListNode*curr,ListNode*prev,int t)
 {
     tt=curr->next;
     curr->next=prev;
     if(t==0)
     {
         curr->next=prev;
         return curr;
     }
     
     return rev(tt,curr,t-1);
 }
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode*prev=NULL,*p1=A,*curr;
    int k=1;
    while(k<B-1)
    {
        k++;
        p1=p1->next;
    }
    if(B==1)
    {
        
        A=rev(A,NULL,C-B);p1->next=tt;
        
    }
    else
    {
        prev=p1;
        curr=p1->next;
        //curr->next=tt;
        prev->next=rev(curr,NULL,C-B);curr->next=tt;
    }
    return A;
}
