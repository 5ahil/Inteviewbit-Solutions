/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])*/
int f(vector<int>&A,vector<int>&B){
    int n=A.size();
    if(n<2)return n;
    int mx=0;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n-1;i++){
        int curr=0,zero=0,ovrlp=0;
        for(int j=i+1;j<n;j++){
            int nume=B[i]-B[j];
            int deno=A[i]-A[j];
            if(nume==0&&deno==0){
                ovrlp++;
            }
            else if(deno==0){
                zero++;
            }
            else{
                int comm=__gcd(nume,deno);
                nume=nume/comm;deno/=comm;
                mp[make_pair(nume,deno)]++;
                curr=max(curr,mp[make_pair(nume,deno)]);
            }
            curr=max(curr,zero);
        }
        mx=max(mx,curr+ovrlp+1);
        mp.clear();
    }
    return mx;
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    return f(A,B);
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

