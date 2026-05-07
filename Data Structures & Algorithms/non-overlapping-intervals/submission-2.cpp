class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, n = intervals.size(), pre = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] < pre)
            {
                ans++;
                pre = min(intervals[i][1], pre);
            }
            else
                pre = intervals[i][1];
        }
        return ans;
    }
};
