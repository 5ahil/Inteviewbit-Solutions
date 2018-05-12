/*Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    } 
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.

Seen t*/
vector<string> f(string s){
    int n=s.length();vector<string>ans;string kk="";kk+=s[0];
    int i=1;int line=1;ans.push_back(kk);string ss="";
    while(i<n)
    {
       int k=0;
       while(k<line)
       {
           ss+="\t";k++;
       }
       if(s[i]=='{'||s[i]=='[')
       {
           ss+=s[i];
           ans.push_back(ss);ss="";
           line++;i++;
       }
       else if(s[i]==',')
       {
           
           i++;
           ss="";
       }
       else if(s[i]=='}'||s[i]==']')
       {
           
           
                ss+=s[i];
                if(i<n && s[i+1]==',')
                {
                    ss+=',';
                    
                    i++;line++;
                }
                ans.push_back(ss);
                ss="";
                line--;i++;
           
           
       }
       else
       {
           while(i<n&& s[i]!='{'&&s[i]!='['&&s[i]!='}'&&s[i]!=']'&&s[i]!=',')
           {
               ss+=s[i];
               i++;
           }
           if(s[i]==',')ss+=',';
           if(s[i]=='}'||s[i]==']')line--;
           ans.push_back(ss);
           ss="";
       }
       
    }
    return ans;
}
vector<string> Solution::prettyJSON(string A) {
    return f(A);
    
}
