/*Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.*/
int Solution::largestRectangleArea(vector<int> &A) {
    stack<int>s;
    int i=0,mx=0;
    while(i<A.size())
    {
        if(s.empty()||A[s.top()]<=A[i])
        {
            s.push(i++);
        }
        else
        {
            int top=s.top();
            s.pop();
            int nmx=A[top]*(s.empty()?i:i-s.top()-1);
            if(nmx>mx)
            {
                mx=nmx;
            }
        }
    }
    while(!s.empty())
    {
        int top=s.top();
            s.pop();
            int nmx=A[top]*(s.empty()?i:i-s.top()-1);
            if(nmx>mx)
            {
                mx=nmx;
            }
    }
    return mx;
}


