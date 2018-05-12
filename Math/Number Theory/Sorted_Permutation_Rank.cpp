/*Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba*/
/*void Solution:: fact(int n, vector<int> &fac)
{
    long long int f=1;
    fac.push_back(1);
    for(int i=2;i<=n;i++)
    {
        f=(f*i)%1000003;
        fac.push_back(f);
    }
    return;
}*/
int Solution::findRank(string A) {
    vector<int>fac;
    long long int f=1;
    fac.push_back(1);
    for(int i=1;i<=A.length();i++)
    {
        f=(f*i)%1000003;
        fac.push_back(f);
    }
    //fact(A.length(),fac);
    int a[256];
    memset(a,0,sizeof(a));
    for(int i=0;i<A.length();i++)
    {
        a[A[i]]++;
    }
    long long int rank=1;
    for(int i=0;i<A.length();i++)
    {
        int less=0;
        for(int j=0;j<A[i];j++)
        {
            less+=a[j];
        }
        rank=(rank+((long long)fac[A.length()-i-1] )*less)%1000003;
        a[A[i]]--;
    }
    return rank;
}
