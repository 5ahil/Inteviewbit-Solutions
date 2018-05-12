/*You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long A_minus_B=0,A_plus_B,ASQR_SUM=0,ESQR_SUM=0;
    for(int i=0;i<A.size();i++){
        A_minus_B+=(A[i]-(i+1));
        A_plus_B+=((long long)A[i]*(long long)A[i])-(long long)(i+1)*(long long)(i+1);
        
    }
    A_plus_B/=A_minus_B;
    vector<int>ans;
    ans.push_back((A_minus_B+A_plus_B)/2);
    ans.push_back((A_plus_B-A_minus_B)/2);
    return ans;
}
