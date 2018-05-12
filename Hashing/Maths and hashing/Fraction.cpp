/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"*/
string f(int a,int b){
    long long A=a,B=b;A=abs(A);B=abs(B);
    bool is_neg=(a^b)<0;
    string ans=is_neg&&A?"-":"";
    ans+=to_string(A/B);
    if(A%B==0){
        return ans;
    }
    ans+=".";
    map<int,int>mp;
    A=A%B;int pos=-1;
    while(A){
        A=A*10;
        if(mp.find(A)==mp.end()){
            mp[A]=ans.length();
        }
        else{
            pos=mp[A];
            break;
        }
        ans+=to_string(A/B);
        A=A%B;
    }
    if(pos==-1)
    {
        return ans;
    }
    return ans.substr(0,pos)+"("+ans.substr(pos)+")";
}
string Solution::fractionToDecimal(int A, int B) {
    return f(A,B);
}

