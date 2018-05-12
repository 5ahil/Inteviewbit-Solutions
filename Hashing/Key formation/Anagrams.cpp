/*Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.*/
vector<vector<int> > Solution::anagrams(const vector<string> &A) {

    map<string, int>mp;int cnt=1;
    vector<vector<int>>ans;
    for(int i=0;i<A.size();i++)
    {
        string s=A[i];
        sort(s.begin(),s.end());
        if(mp[s]==0)
        {
            mp[s]=cnt++;
            vector<int>t;
            ans.push_back(t);
        }
    }
    //map<string,vector<int>>::iterator i;
    
    for(int i=0;i<A.size();i++)
    {
        string s=A[i];
        sort(s.begin(),s.end());
        //sort(A[i].begin(),A[i].end());
        ans[mp[s]-1].push_back(i+1);
    }
    return ans;
}

