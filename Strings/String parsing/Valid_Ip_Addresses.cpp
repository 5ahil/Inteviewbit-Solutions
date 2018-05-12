/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)8*/
bool valid(string ss)
{
    int n=ss.length();
    int i=0;
    while(ss[i]!='.')i++;
    if(ss[0]=='0'&&i>1)return false;
    //cout<<"a="<<ss.substr(0,i)<<endl;
    if(stoi(ss.substr(0,i))>255)return false;
    int j=++i;
    //i=0;
    while(ss[i]!='.')i++;
    if(ss[j]=='0'&&i-j>1)return false;
    //cout<<"b="<<ss.substr(j,i-j)<<endl;
    if(stoi(ss.substr(j,i-j))>255)return false;
    j=++i;
    //i=0;
    while(ss[i]!='.')i++;
    if(ss[j]=='0'&&i-j>1)return false;
    //cout<<"c="<<ss.substr(j,i-j)<<endl;
    if(stoi(ss.substr(j,i-j))>255)return false;
    j=++i;
    //i=0;
    while(ss[i]!='\0')i++;
    if(ss[j]=='0'&&i-j>1)return false;
    //cout<<"d="<<ss.substr(j,i-j)<<endl;
    if(stoi(ss.substr(j,n-j))>255)return false;
    return true;
}

vector<string> Solution::restoreIpAddresses(string s) {
    int n=s.length();
	//string kk="0.0.44.0";
	//if(valid(kk))cout<<"y\n";
	//else cout<<"n\n";
	//return 0;
	vector<string>ans;
	if(n>12)
	{
	    return ans;
	}
	
	for(int i=1;i<4;i++)
	{   
	    string ss1="";
	    ss1=s.substr(0,i);
	    ss1+=".";
	    for(int j=i+1;j<i+4;j++)
	    {
	        if(j>=n-1)continue;
	        string ss2=(s.substr(i,j-i));
	        ss2+=".";
	        for(int k=j+1;k<j+4;k++)
	        {
	            if(k>n-1)continue;
	            string ss3=(s.substr(j,k-j));
	            ss3+=".";
	            string ss4=(s.substr(k,n-k));
	            //cout<<ss1+ss2+ss3+ss4<<endl;
	            //continue;
	            string ss="";
	            ss=ss1+ss2+ss3+ss4;
	            if(valid(ss))
	            {
	                ans.push_back(ss);
	            }
	        }
	    }
	}
	return ans;
}
