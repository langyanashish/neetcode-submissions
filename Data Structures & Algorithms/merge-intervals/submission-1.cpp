class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int pre = 0;
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] <= intervals[pre][1])
            {
                intervals[pre][1] = max(intervals[i][1], intervals[pre][1]);
                intervals[i][0] = -1;
            }
            else
                pre = i;
        }
        vector<vector<int>> res;
        for(auto i : intervals)
            if(i[0] >= 0)
                res.push_back(i);
        return res;
    }
};
