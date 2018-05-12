/*For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1*/
int subNum(int l,unordered_map <int,int> &mymap,const vector<int> &A){
    int product=1;
    int i,p=0;
    for(i=0;i<l-1;i++)
        product*=A[i];
    
    for(i=l-1;i<A.size();i++){
        product*=A[i];
        if(mymap.find(product)!=mymap.end())
            return 0;
        else mymap[product]=1;
        product/=A[p];
        p++;
    }
    return 1;
}
int Solution::colorful(int A) {
    if(A<10)
        return 1;
    vector<int> array;
    int digit;
    while(A>0){
        digit=A%10;
        if(digit==0)
            return 0;
        array.push_back(digit);
        A=A/10;
    }
   unordered_map<int,int> mymap;
   for(int i=1;i<=array.size();i++)
    if(!subNum(i,mymap,array))
        return 0;
    return 1;
    
}
/*
int f(vector<int>&A)
{
    int old[340000];
    for(int len=1;len<=A.size();len++)
    {
        for(int i=0;i<=A.size()-len;i++)
        {
            int k=i;int prod=1;
        
            while(k<i+len&&k<A.size())
            {
                prod*=A[k];k++;
            }
            //cout<<prod<<endl;
            if(prod>362880||old[prod]==1)return 0;
            old[prod]=1;
        }
    }
    return 1;
}
int Solution::colorful(int n) {
    vector<int>A;
    if(n==0||n==1)
    {
        return 1;
    }
    else
    while(n>0)
    {
        //if(n%10==1)return 0;
        A.push_back(n%10);
        n=n/10;
    }
    int i=0;int j=A.size()-1;
    while(i<j)
    {
        int t=A[i];
        A[i]=A[j];
        A[j]=t;i++;j--;
    }
    if(A[0]==1)
    {
        return 0;
    }
    return f(A);
}*/

