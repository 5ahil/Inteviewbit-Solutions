/*Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool mycmp(Interval a,Interval b)
 {
     return a.start<b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    vector<Interval> aa;
    sort(A.begin(),A.end(),mycmp);
    Interval f(A[0].start,A[0].end);
    
    aa.push_back(f);int c=0;
    //vector<Interval>::iterator i=A.begin();i++;
    for(int i=1;i<A.size();i++)
    {
        if(A[i].start<=aa[c].end)
        {
            aa[c].end=max(A[i].end,aa[c].end);
            //cout<<"aa["<<c<<"]end= "<<aa[c].end<<endl;
        }
        else
        {
            aa.push_back(A[i]);
            
            //cout<<"c="<<c<<endl;
            c++;
        }
    }
    return aa;
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
