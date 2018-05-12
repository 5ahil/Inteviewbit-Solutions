/*The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.*/
vector<int>  f(int n) {
    vector<vector<int> >ans;
    vector<int>ms;
    ms.push_back(0);
    ms.push_back(1);int k=2;
    for(int i=2;i<1<<n;i*=2)
    {
        for(int j=i-1;j>=0;j--)
        {
            ms.push_back(ms[j]);
        }
        for(int j=0;j<i;j++)
        {
            ms[j]=ms[j];
        }
        for(int j=i;j<2*i;j++)
        {
            ms[j]=k+ms[j];
        }
        k=k*2;
    }
    
    
    return ms;
}
vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    return f(A);
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

