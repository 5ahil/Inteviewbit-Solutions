/*The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
 In this case, just concatenate the number to the answer.
so if n = 11, k = 1, ans = "1234567891011" 
Whats the maximum value of n and k?
 In this case, k will be a positive integer thats less than INT_MAX.
n is reasonable enough to make sure the answer does not bloat up a lot. 
Seen this question in a real interview beforeYesNo
Notes*/
int fact[14];
string rec(int num_left,int setsize,int k,map<int,bool>&is_already_inserted,string ins)
{
    if(k==0||num_left==1)
    {
        for(int i=0;i<setsize;i++)
        {
            if(!is_already_inserted[i+1])
            ins+=to_string(i+1);  //add remaining numbers to string
        }
        return ins;
    }
    int t=k/fact[num_left-1];
    //go to the t th number in remaining numbers( numbers which are not fixed yet)
    int i=0,t1=t;
    for( i=0;i<setsize;i++)
    {
        if(is_already_inserted[i+1]==false)
        {
            if(!t--)
            {
                break;    // get the t_th number from non visited numbers
            }
        }
    }
    is_already_inserted[i+1]=true;   // i+1 th number fix in string
    k=k-(t1*fact[num_left-1]);
    //recur for remaining.
    return rec(num_left-1,setsize,k,is_already_inserted,ins+to_string(i+1));// i+1 th number fix in string
}
 string  f(int num_left,int k) {
    
    map<int,bool>is_already_inserted;
    fact[1]=1;
    for(int i=2;i<14;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    return rec(num_left,num_left,k-1,is_already_inserted,"");
}

string Solution::getPermutation(int A, int B) {
    f(A,B);
}

