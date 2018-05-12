/*Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)*/	
typedef struct snode
{
    int i,j,sum;
}snode;
vector<int> Solution::equal(vector<int> &A) {
    vector<snode>ans;int n=A.size();vector<int>a;
    if(n<4)return a;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            snode t;
            int sm=A[i]+A[j];
            t.i=i;
            t.j=j;
            t.sum=sm;
            ans.push_back(t);
        }
    }
    int smsize=((n-1)*n)/2;
    for(int i=0;i<smsize-1;i++)
    {
        for(int j=0;j<smsize;j++)
        {
            if(ans[i].sum==ans[j].sum&&ans[i].i<ans[j].i&&ans[i].j!=ans[j].i&&ans[i].j!=ans[j].j)
            {
                a.push_back(ans[i].i);a.push_back(ans[i].j);
a.push_back(ans[j].i);            a.push_back(ans[j].j);
return a;
                
            }
        }
    }
    
    return a;
}

