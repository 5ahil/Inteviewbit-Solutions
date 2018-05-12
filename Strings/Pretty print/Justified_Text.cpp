/*Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]*/
vector<string> fun(vector<string>&a,int k)
{
    vector<string> re;int n=a.size();
    int i=0;string ss;
    int cnt;int space=0;
    while(i<n)
    {
        ss=a[i];i++;
        int j=i;space=0;cnt=ss.length();space=0;
        while(i<n && cnt+1+a[i].length()<=k)
        {
            cnt+=(1+a[i].length());
            i++;space++;
        }
        if(space==0||i==n)
        {
           if(space==0)
           {
                int k1=0;
                while(k1<k-a[i-1].length())
                {
                    ss+=" ";
                    k1++;
                }

           }
           else
           {
               int k1=0;
                while(space--)
                {
                    ss+=" ";
                    ss+=a[j++];
                }
                int pp=ss.length();
                while(k1<k-pp)
                {
                    ss+=" ";
                    k1++;
                }

           }
        }
        else
        {
            int tab_size=(k-cnt)/space;
            int remaining = k-cnt-tab_size*space;
            string tab="";
            int k1=0;
            while(k1<tab_size)
            {
                tab+=" ";
                k1++;
            }
            while(space--)
            {
                ss+=(" "+tab);
                if(remaining>0)
                {
                    ss+=" ";
                    remaining--;
                }
                ss+=a[j++];
            }

        }
        re.push_back(ss);
            ss="";
    }
    return re;
}
 
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    return fun(A,B);
}
