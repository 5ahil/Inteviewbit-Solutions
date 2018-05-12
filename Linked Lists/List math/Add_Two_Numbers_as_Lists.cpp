/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry=0;
    ListNode*h1=A,*h2=B,*p=A,*p2=B;
    while(h1&&h2)
    {
        h1->val+=(carry+h2->val);carry=0;
        if(h1->val>9)
        {h1->val-=10;
        carry=1;}
        p=h1;p2=h2;
        h1=h1->next;
        h2=h2->next;
    }
    if(h1==NULL)
    {
        p->next=h2;
        while(h2)
        {
            h2->val+=carry;
            carry=0;
            if(h2->val>9)
            {
                h2->val-=10;
                carry=1;
            }
            p2=h2;
            h2=h2->next;
        }
        if(carry==1)
        {
            ListNode*kk=(ListNode*)malloc(sizeof(ListNode));
            kk->val=1;
            kk->next=NULL;
            p2->next=kk;
        }
        return A;
    }
    while(h1)
    {
        h1->val+=carry;
        carry=0;
        if(h1->val>9)
        {h1->val-=10;
        carry=1;}
        p=h1;
        h1=h1->next;
    }
    if(carry==1)
        {
            ListNode*kk=(ListNode*)malloc(sizeof(ListNode));
            kk->val=1;
            kk->next=NULL;
            p->next=kk;
        }
        return A;
    
}
