/*Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode*merge(ListNode*h1,ListNode*h2)
{
    ListNode*ih1=h1,*ih2=h2,*nih1,*nih2;//cout<<"d";
    if(h1->val>h2->val)
    {
        ih2=h2->next;
        h2->next=h1;
        
        h1=h2;ih1=h1;
    }
    else
    {
       /* nih1=ih1->next;
        nih2=ih2->next;
        ih1->next=ih2;
        ih2->next=nih1;
        ih2=nih2;*/
        
    }
    while(ih1->next&&ih2)
    {
        if(ih1->next->val>ih2->val)
        {
            nih2=ih2->next;
            nih1=ih1->next;
            ih1->next=ih2;
            ih2->next=nih1;
            ih2=nih2;
            ih1=ih1->next;
        }
        else
        {
            ih1=ih1->next;
        }
    }while(ih1->next)ih1=ih1->next;
    ih1->next=ih2;
    return h1;
}
ListNode*f2(ListNode*h,int cnt)
{
    if(h==NULL||h->next==NULL)return h;
    int k=1;ListNode*p1=h;
    //cout<<"s";
    while(k<cnt/2)
    {
        p1=p1->next;k++;
    }
    //if(cnt==2)
    
    //cout<<"forList "<<h->val<<" of len="<<cnt<<endl;
    //cout<<"calling fun "<<h->val<<" of len="<<k<<" and fun2 "<<(p1->next)->val<<" of len="<<cnt-k<<endl;
    ListNode*np1=p1->next;
    p1->next=NULL;
    //cout<<"calling h1\n";print(h);
    ListNode*h1=f2(h,cnt/2);
    ListNode*h2=f2(np1,cnt-k);
    //cout<<"calling h1\n";print(h1);
    //cout<<"Calling h2\n";print(h2);
    //cout<<"closed forList "<<h->val<<" of len="<<cnt<<endl;
    h=merge(h1,h2);
    //cout<<"nad become h\n";print(h);
    return h;
    
}
ListNode* Solution::sortList(ListNode* h) {
    if(!h||!h->next)return h;
    int cnt=0;ListNode*p1=h;
    //cout<<"t";
    while(p1)
    {
        cnt++;
        p1=p1->next;
    }
    h=f2(h,cnt);
    return h;
}
