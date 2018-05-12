/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector <Interval> ans;int start,end,j;Interval v;
    for(int i=0;i<intervals.size();i++)
    {
        if(newInterval.end<intervals[i].start)
        {
            ans.push_back(newInterval);
            for( j=i;j<intervals.size();j++)
            {
                ans.push_back(intervals[j]);
            }
            return ans;
        }
        else
        {
            if(newInterval.start<=intervals[i].end)
            {
                start=min(newInterval.start,intervals[i].start);
                while(i<intervals.size()&& newInterval.end>intervals[i].end)
                {
                    i++;
                }
                if(newInterval.end<intervals[i].start)
                {
                    v.start=start;
                    v.end=newInterval.end;
                    ans.push_back(v);
                    for( j=i;j<intervals.size();j++)
                    {
                        ans.push_back(intervals[j]);
                    }
                    return ans;
                    
                }
                else if(i==intervals.size())
                {
                    v.start=start;
                    v.end=newInterval.end;
                    ans.push_back(v);
                    return ans;
                }
                else
                {
                    v.start=start;
                    v.end=intervals[i].end;
                    ans.push_back(v);
                    for( j=i+1;j<intervals.size();j++)
                    {
                        ans.push_back(intervals[j]);
                    }
                    return ans;

                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        
    }
    ans.push_back(newInterval);
    return ans;
}
