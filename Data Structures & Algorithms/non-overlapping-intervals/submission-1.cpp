class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ansL = 0, ansR = 0, n = intervals.size(), pre = 0, post = n-1;
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] < intervals[pre][1])
                ansL++;
            else
                pre = i;
        }

        for(int i = n-2; i>=0; i--)
        {
            if(intervals[i][1] > intervals[post][0])
                ansR++;
            else
                post = i;
        }
        return min(ansL, ansR);
    }
};
