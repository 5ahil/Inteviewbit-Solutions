/*Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0
*/
int Solution::braces(string A) {
    stack<char>stk;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==')')
        {
            int a=0;
            while(stk.top()!='(')
            {
                stk.pop();a++;
            }
            if(a<2)return 1;
            stk.pop();
        }
        else
        {
            stk.push(A[i]);
        }
    }
    return 0;
}
