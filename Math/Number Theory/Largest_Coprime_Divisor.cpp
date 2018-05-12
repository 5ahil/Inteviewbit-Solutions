/*You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5*/
int fun (int a,int b)
{
    if(a%b==0)
    return b;
    
    return fun(b,a%b);
}
int Solution::cpFact(int A, int B) {
    while(fun(max(A,B),min(A,B)) != 1){
    A = A / fun(max(A,B),min(A,B));
  } 
  return A;
}
