/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6*/
  int Solution::evalRPN(vector<string> &A) {
    int ans=0;
    stack<int>stk;
    for(int i=0;i<A.size();i++)
    {
        string s=A[i];
        if(s=="+")
        {
            int b=stk.top();stk.pop();
            int a=stk.top();stk.pop();
            a+=b;
            stk.push(a);
        }
        else if(s=="-")
        {
            int b=stk.top();stk.pop();
            int a=stk.top();stk.pop();
            a-=b;
            stk.push(a);
        }
        else if(s=="*")
        {
            int b=stk.top();stk.pop();
            int a=stk.top();stk.pop();
            a*=b;
            stk.push(a);
        }
        else if(s=="/")
        {
            int b=stk.top();stk.pop();
            int a=stk.top();stk.pop();
            a/=b;
            stk.push(a);
        }
        else
        {
            stk.push(stoi(s));
        }
    }
    return stk.top();
}
