/*Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.*/
string Solution::simplifyPath(string A) {
    stack<string>s;
    if(A[A.length()-1]!='/')A+="/";
    for(int i=0;i<A.length();)
    {
        if(A[i]=='/')
        {
            while(A[i]=='/')i++;
            string ss="";
            if(i==A.length())break;
            while(A[i]!='/')
            {
                ss+=A[i];i++;
            }
            if(ss=="..")
            {
                if(!s.empty())s.pop();
            }
            else if(ss!=".")
            {
                s.push(ss);
            }
            
        }
    }
    stack<string>s1;
    while(!s.empty())
    {
        s1.push(s.top());
        s.pop();
    }
    string ss="";
    while(!s1.empty())
    {
        ss+="/";
        ss+=s1.top();
        s1.pop();
    }
    if(ss=="")return "/";
    return ss;
}
