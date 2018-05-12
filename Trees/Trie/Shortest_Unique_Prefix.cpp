/*Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. */
typedef struct node{
    struct node *character[26];
    int count;
    bool isend;
}TrieNode;
TrieNode*makeNode(){
    TrieNode*t=new TrieNode();
    t->isend=false;
    t->count=0;
    for(int i=0;i<26;i++){
        t->character[i]=NULL;
    }
    return t;
}
TrieNode*insert(TrieNode*root,string key){
    TrieNode*ptr=root;
    for(int i=0;i<key.length();i++){
        if(!ptr->character[key[i]-'a']){
            ptr->character[key[i]-'a']=makeNode();
            
        }
        ptr->character[key[i]-'a']->count++;
        ptr=ptr->character[key[i]-'a'];
        
    }
    ptr->isend=true;
    return root;
}

string pref(TrieNode*root,string key){
    string k="";
    for(int i=0;i<key.length();i++){
        k+=key[i];
        if(root->character[key[i]-'a']->count==1)
        return k;
        root=root->character[key[i]-'a'];
    }
    return k;
}
vector<string>f(vector<string>A){
    TrieNode*root=makeNode();
    vector<string>ans;
    for(int i=0;i<A.size();i++){
        root=insert(root,A[i]);
    }
    //if(search(root,"zebra"))cout<<"found\n";
    for(int i=0;i<A.size();i++){
        string k=pref(root,A[i]);
        ans.push_back(k);
    }
    return ans;
}
vector<string> Solution::prefix(vector<string> &A) {
    return f(A);
}

