/*Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.*/
bool compare(string s1,string s2)
{
    
    if(s1+s2>s2+s1)
    
    return true;
    return false;

}
string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> ss;int cc=0;
    
    for(int i=0;i<A.size();i++)
    {
        ss.push_back(to_string(A[i]));
        if(A[i]!=0)cc=1;
    }
    sort(ss.begin(),ss.end(),compare);string s="";
    for(int i=0;i<A.size();i++)
    {
        s+=ss[i];
    }
    if(cc)return s;else return "0";
}
