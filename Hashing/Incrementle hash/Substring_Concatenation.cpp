/*You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).*/
vector<int>f(string s,const vector<string>l)
{
    int sl=s.length();
    int n=l.size();
    int len=l[0].length();
    map<string,int>mp;vector<int>ans;
    //cout<<"strat "<<sl<<" "<<n<<" "<<len<<endl;
    for(int i=0;i<n;i++)
    {
        mp[l[i]]++;
    }
     map<string,int>mp1(mp);
    // mp1(mp);
     int put=0,cnt=0;
    for(int i=0;put<sl-len*n+1;)
    {
        if(mp1[s.substr(i,len)]>0)
        {
            mp1[s.substr(i,len)]--;cnt++;
            //cout<<s.substr(i,len)<<" -passed i="<<i<<" "<<put<<endl;
            if(cnt==n)
            {
                ans.push_back(put);cnt=0;
                for(int i=0;i<n;i++)
            {
                mp1[l[i]]=0;
            }
                for(int i=0;i<n;i++)
                {
                    mp1[l[i]]++;
                }
                //cout<<put<<"- ans\n";
                put++;i=put;
            }
            else i+=len;
        }
        else
        {
            //map<string,int>mp1(mp);
            for(int i=0;i<n;i++)
            {
                mp1[l[i]]=0;
            }
            for(int i=0;i<n;i++)
            {
                mp1[l[i]]++;
            }
            //cout<<s.substr(i,len)<<" -failed i="<<i<<" "<<put<<endl;
            cnt=0;
            put++;
            i=put;
        }
    }
    
    return ans;
}
vector<int> Solution::findSubstring(string A, const vector<string> &B) {

    return f(A,B);
}

