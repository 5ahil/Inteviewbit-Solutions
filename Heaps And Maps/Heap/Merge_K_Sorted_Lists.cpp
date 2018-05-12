/*Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
ListNode*merge(ListNode*A,ListNode*B){
    ListNode*p1,*head;
    if(A==NULL)return B;
    if(B==NULL)return A;
    if(A->val<B->val){
        head=A;
        A=A->next;
    }
    else{
        head=B;
        B=B->next;
    }
    p1=head;
    while(A&&B){
        if(A->val<B->val){
            p1->next=A;
            p1=p1->next;
            A=A->next;
        }
        else{
            p1->next=B;
            p1=p1->next;
            B=B->next;
        }
    }
    if(A){
        p1->next=A;
    }
    else{
        p1->next=B;
    }
    return head;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    for(int i=1;i<A.size();i++)
    {
        A[0]=merge(A[0],A[i]);
    }
    return A[0];
}*/
struct compare{
    public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    ListNode*head=NULL,*tail;
    priority_queue<ListNode*,vector<ListNode*>,compare>pq;
    for(int i=0;i<A.size();i++){
        if(A[i])pq.push(A[i]);
    }
    while(!pq.empty()){
        ListNode*top=pq.top();
        pq.pop();
        if(top->next){
            pq.push(top->next);
        }
        if(!head){
            head=top;
            tail=top;
        }
        else{
            tail->next=top;
            tail=tail->next;
        }
    }
    return head;
}

