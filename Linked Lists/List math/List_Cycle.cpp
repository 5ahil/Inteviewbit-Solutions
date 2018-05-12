/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode*A)
{
    if(A==NULL)return NULL;
    ListNode*s,*f,*p1,*p2,*p3;
    s=A;
    f=A->next;
    //cout<<"good so far\n";
    while(f)
    {
        if(s==f)
        {
            break;
        }
        f=f->next;
        if(!f)return NULL;
        s=s->next;
        f=f->next;
    }
    
    if(!f)return NULL;
    int len_of_cyc=1;
    f=f->next;
    while(s!=f)
    {
        f=f->next;  len_of_cyc++;      
    }
    s=f=A;
    while(len_of_cyc--)
    {
        f=f->next;
    }
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    return s;
}