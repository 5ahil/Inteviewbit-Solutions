/*Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode*f(ListNode*h,int k)
 {
     if(k==1||h==NULL||h->next==NULL)
	{
	    return h;
	}
	int m=k-1;ListNode*p1,*p2,*t;
	p1=h;
	p2=p1->next;
	while(m--)
	{
	    t=p2->next;
	    p2->next=p1;
	    p1=p2;
	    p2=t;
	}
	
	h->next=f(t,k);
	return p1;
 }
ListNode* Solution::reverseList(ListNode* h, int k) {
    h=f(h,k);
    while(h)
    {
        cout<<h->val<<" ";h=h->next;
    }
    return NULL;
}
